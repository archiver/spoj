#include <stdio.h>

typedef unsigned long long ull;
ull fact[14];

void  init()
{
  fact[0]=1L;
  for(int i=1;i<14;++i)
    fact[i]=fact[i-1]*i;
}

int main()
{
  int n,k;
  ull res;
  int t;
  init();

  while(scanf("%d %d",&n,&k)!=EOF)
  {
    res=fact[n];
    for(int i=0;i<k;++i)
    {
      scanf("%d",&t);
      res/=fact[t];
    }
    printf("%llu\n",res);
  }
  return 0;
}
