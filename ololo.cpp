#include <stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int res=0, v;
  for(int i=0;i<n; ++i)
  {
    scanf("%d",&v);
    res=res^v;
  }
  printf("%d\n",res);
  return 0;
}
