#include <stdio.h>

int gcd(int a, int b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}

inline int abs(int x)
{
  return x<0?-x:x;
}

int calculate(int a, int b)
{
  int za=abs(a);
  int zb=abs(b);

  int r=za>zb?gcd(za,zb):gcd(zb,za);
  a=a/r;
  b=b/r;
  return abs(a-b);
}

int main()
{
  int t;
  scanf("%d",&t);
  int a, b;
  while(t--)
  {
    scanf("%d %d",&a,&b);
    printf("%d\n",calculate(a,b));
  }
  return 0;
}
