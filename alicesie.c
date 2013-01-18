#include <stdio.h>
#define N 10000001

int vals[N];

void init()
{
   vals[2]=1;
   int i,end=2;
   for(i=3;i<N;++i)
   {
     if(i%end)
       vals[i]=vals[i-1]+1;
     else 
     {
       vals[i]=vals[i-1];
       end+=1;
     }
   }
}

int main()
{
  int t,n;
  init();
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    printf("%d\n",vals[n]);
  }
  return 0;
}
