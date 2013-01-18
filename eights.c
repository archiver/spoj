#include <stdio.h>

int main()
{
  int t;
  unsigned long long n;
  int i=0;
  scanf("%d",&t);
  for(i=0;i<t;++i)
  {
    scanf("%lld",&n);
    if(n%2)
      printf("%lld92\n",1L+(n/2)*5);
    else
      printf("%lld42\n",4L+((n-1)/2)*5);
  }
  
  return 0;
}
