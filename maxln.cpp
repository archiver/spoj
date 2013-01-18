#include <stdio.h>

int main()
{
  int t;
  unsigned long long n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%llu",&n);
    printf("%llu.25\n",4*(n*n));
  }
  return 0;
}
