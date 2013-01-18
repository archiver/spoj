#include <stdio.h>
#include <cmath>

int main()
{
  int t,n;
  int val;
  const double pi = 3.1415926535897932385;
  const double e = 2.71828182845904523536;
  const double c = 0.5*log10(sqrt(pi*2));
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    if(0==n || 1==n) printf("1\n");
    else
    {
      val=ceil((n+0.5)*log10(n)-n*log10(e)+c);
      printf("%d\n",int(val));
    }
  }
  return 0;
}
