#include <stdio.h>
#include <cmath>

using namespace std;

bool is_beenum(int n)
{
  int x=(n-1);
  if(x%3) return false;
  x=x/3;
  int a=sqrt(x);
  return (x==a*(a+1));
}

int main()
{
  int n;
  while(1)
  {
    scanf("%d",&n);
    if(n==-1) break;
    if(is_beenum(n)) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}
