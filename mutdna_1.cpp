#include <stdio.h>
using namespace std;

#define N 1000000
char input[N];
bool state[N];

int solve(int n)
{ 
   int i,pos=n-1;
   for(i=0;i<n;++i)
      state[i]=input[i]-'A';
   int res=0;

   while(1)
   {
      for(i=pos;i>=0;--i)
	 if(state[i]) break;
      pos=i;
      if(i<0) break;
      if(pos==0) { res+=1; break; }
      if(state[pos-1]) //flip prefix
      {
	 for(i=pos;i>=0;--i)
	    state[i]=state[i]^1;
	 res+=1;
      }
      else //flip pos
      {
	 state[pos]=state[pos]^1;
	 res+=1;
      }
   }
   printf("%d\n",res);
}

int main()
{
   int n;
   scanf("%d",&n);
   scanf("%s",&input);
   solve(n);
   return 0;
}
