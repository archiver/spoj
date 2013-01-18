#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 1000

int main()
{
  int t,n;
  int i,res;
  int m[N],w[N];

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(i=0;i<n;++i) scanf("%d",&m[i]);
    for(i=0;i<n;++i) scanf("%d",&w[i]);
    sort(m,m+n);
    sort(w,w+n);
    res=0;
    for(i=0;i<n;++i)
      res+=(m[i]*w[i]);
    printf("%d\n",res);
  }
  return 0;
}
