#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 100
int grid[N][N];
int ans[N][N];

int solve(int n, int m)
{
  int i,j;
  for(j=0;j<m;++j)
    ans[n-1][j]=grid[n-1][j];

  for(i=n-2;i>=0;--i)
  {
    for(j=0;j<m;++j)
    {
      ans[i][j]=ans[i+1][j];
      if(j-1>=0) ans[i][j]=min(ans[i][j],ans[i+1][j-1]);
      if(j+1<m) ans[i][j]=min(ans[i][j],ans[i+1][j+1]);
      ans[i][j]+=grid[i][j];
    }
  }

  int res=ans[0][0];
  for(j=1;j<m;++j)
    res=min(res,ans[0][j]);
  return res;
}

int main()
{
  int n,m;
  int i,j;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;++i)
    for(j=0;j<m;++j)
      scanf("%d",&grid[i][j]);
  printf("%d\n",solve(n,m));
  return 0;
}
