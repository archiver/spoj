#include <stdio.h>
#include <math.h>

int divsum(int n)
{ 
  if(n==1) return 0;
  int res=1,i=0;
  int limit=sqrt(n);
  for(i=2;i<=limit;++i)
    if(!(n%i)) res+=(i+n/i);
  if(limit*limit==n) res-=limit;
  return res;
}

int main()
{
  int t;
  int num;
  scanf("%d",&t);
  int i;
  for(i=0;i<t;++i)
  {
    scanf("%d",&num);
    printf("%d\n",divsum(num));
  }
  return 0;
}
