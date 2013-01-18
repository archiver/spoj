#include <stdio.h>

typedef unsigned long long ull;

int main()
{
  ull n;
  scanf("%llu",&n);
  if(0 == (n&(n-1))) //power of 2 
    printf("TAK\n");
  else printf("NIE\n");
  return 0;
}
