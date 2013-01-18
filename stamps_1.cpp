#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 1000
#define S 1000000
#define INF 100000000
int nums[N];
int vals[S];

void solve(int t, int n, int k)
{
  sort(nums,nums+n);
  
  int i,j;
  int s=0;

  for(i=0;i<n;++i) s+=nums[i];
  if(k>s)
  {
     printf("Scenario #%d:\n",t);
     printf("impossible\n\n");
     return;
  }

  for(i=0;i<=s;++i) vals[i]=INF;
  vals[0]=0;

  for(i=0;i<n;++i)
    for(j=S;j>=nums[i];--j)
      vals[j]=min(vals[j],1+vals[j-nums[i]]);
  
  int ans=INF;
  for(j=k;j<=s;++j)
    if(ans>vals[j]) ans=vals[j];

  printf("Scenario #%d:\n",t);
  printf("%d\n\n",ans);
  return;
}

int main()
{
  int t,v,n,i,j;
  scanf("%d",&t);
  for(i=1;i<=t;++i)
  {
    scanf("%d %d",&v,&n);
    for(j=0;j<n;++j) scanf("%d",&nums[j]);
    solve(i,n,v);
  }
  return 0;
}
