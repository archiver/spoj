#include <stdio.h>
#include <algorithm>

#define INF 10000000
#define N 1000
int top[N];
int down[N];

using namespace std;

inline int MIN(int a, int b)
{
  return a<=b?a:b;
}

int bisect(int s, int e, int v)
{
  int m=s+(e-s)/2;
  if(down[m]==v) return m;
  if(s==e)
  {
    if(down[m]>v) return m;
    else return m+1;
  }
  if(down[m]>v) return bisect(s,m,v);
  else return bisect(m+1,e,v);
}

int mindiff(int n, int m)
{
  sort(down,down+m);

  int mdiff=INF;
  int diff=-1;
  int v=-1,t=0;

  for(int i=0;i<n;++i)
  {
    v=top[i];
    t=bisect(0,m-1,v);
    if(down[t]==v) return 0;
    if(!t) diff=abs(down[t]-v);
    else
    {
      diff=abs(down[t-1]-v);
      diff=MIN(diff,abs(down[t]-v));
    }

    if(mdiff>diff) mdiff=diff;
  }
  return mdiff;
}

int main()
{
  int n,m;

  int t;
  scanf("%d",&t);

  while(t--)
  {
    scanf("%d",&n);
    for(int j=0;j<n;++j) scanf("%d",&top[j]);

    scanf("%d",&m);
    for(int j=0;j<m;++j) scanf("%d",&down[j]);

    printf("%d\n",mindiff(n,m));
  }
  return 0;
}
