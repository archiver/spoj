#include <stdio.h>
#define N 100000

typedef unsigned long long ull;

int a[N];
ull s[N];
ull ss[N];
int n,m;

void precompute()
{
  int i=1;
  s[0]=a[0];
  ss[0]=a[0]*a[0];

  for(;i<n;++i)
  {
    s[i]=s[i-1]+a[i];
    ss[i]=ss[i-1]+a[i]*a[i];
  }
}

ull solution(int u, int v)
{
  ull single, square;
  if(!u)
  {
    single=s[v];
    square=ss[v];
  }
  else
  {
    single=s[v]-s[u-1];
    square=ss[v]-ss[u-1];
  }
  return (single*single+square)/2;
}

int main()
{
  int i,j;
  int u,v;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",&a[i]);
  scanf("%d",&m);
  precompute();
  for(j=0;j<m;++j)
  {
    scanf("%d %d",&u,&v);
    printf("%lld\n",solution(u,v));
  }
  return 0;
}
