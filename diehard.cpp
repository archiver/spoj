#include <stdio.h>
#include <algorithm>
using namespace std;

int costs[][2]={{+3,+2},
   {-5,-10},
   {-20,+5}};

//note that in this problem you can clearly see stack vs loop there is >100 times difference based on iteration status : same with iterators & loops!!

int solve(int h, int a)
{
   int res=0,m;

   while(h>0 && a>0)
   {
      m=max(0,min(h/2,a/8)-1);
      res+=m;

      h=h-2*m; a=a-8*m;
      if(h-2>0 && a-8>0)
      {
	 res+=1;
	 h=h-2;
	 a=a-8;
      }
      else
      {
	 if(h-17>0) //little armour, more health
	 {
	    res+=1;
	    h=h-17;
	    a=a+7;
	 }
	 else      //no health, so we die in next step
	 {
	   res+=1;
	   h=h-2;
	   a=a-8;
	 }
      }
   }

   return res;
}

int main()
{
   int t,h,a;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d %d",&h,&a);
      printf("%d\n",2*solve(h,a)-1);
   }
   return 0;
}
