#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 1000
#define S 1000000
int nums[N];

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
  
  int rs=0;
  for(i=n-1;i>=0;--i)
  {
    rs+=nums[i];
    if(rs>=k) break;
  }

  printf("Scenario #%d:\n",t);
  printf("%d\n\n",n-i);
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
