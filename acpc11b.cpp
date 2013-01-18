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

int mindiff(int n, int m)
{
  sort(down,down+m);

  int mdiff=INF;
  int diff=0;
  int v=-1,t=0;

  for(int i=0;i<n;++i)
  {
     for(int j=0;j<m;++j)
     {
        diff=abs(top[i]-down[j]);
	if(mdiff>diff) mdiff=diff;
     }
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
