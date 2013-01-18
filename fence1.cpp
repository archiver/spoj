#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  float pi = acos(-1);
  float den = 1.0/(2*pi);
  while(1)
  {
     scanf("%d",&n);
     if(!n) break;
     printf("%.2f\n",den*(n*n));
  }
  return 0;
}
