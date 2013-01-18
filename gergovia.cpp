#include <stdio.h>
#define N 100000

long long wines[N];

long long solve(int n)
{
   int i=0;
   long long movement=0LL;
   
   for(i=0;i<n-1;++i)
   {
     wines[i+1]+=wines[i];
     movement=movement+(wines[i]>=0?wines[i]:-wines[i]);
   }
   return movement;
}

int main()
{
  int n,i;
  while(scanf("%d",&n) && n>0)
  {
    for(i=0;i<n;++i) scanf("%lld",&wines[i]);
    printf("%lld\n",solve(n));
  }
  return 0;
}
