#include <stdio.h>
#include <algorithm>
using namespace std;
#define  N 20000
int height[N];

int solve(int n, int k)
{
  if(1==k) return 0;

  int diff=height[k-1]-height[0];
  int mdiff=diff;
  for(int i=1;i+k<=n;++i)
  {
    diff=height[k-1+i]-height[i];
    if(diff<mdiff) mdiff=diff;
  }
  return mdiff;
}

int main()
{
  int t,n,k;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i)
     scanf("%d",&height[i]);
    sort(height,height+n);
    printf("%d\n",solve(n,k));
  }
  return 0;
}
