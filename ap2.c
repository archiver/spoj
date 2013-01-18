#include <stdio.h>
typedef unsigned long long ull;

int main()
{
  int t;
  scanf("%d",&t);
  ull x,y,s;
  ull n,a,d;
  ull i,val;
  while(t--)
  {
    scanf("%llu %llu %llu",&x,&y,&s);
    n=(s<<1)/(x+y);
    d=(y-x)/(n-5);
    a=x-(d<<1);
    printf("%llu\n",n);
    val=a;
    for(i=0;i<n-1;++i)
    {
      printf("%llu ",val);
      val+=d;
    }
      printf("%llu\n",val);
  }
  return 0;
}

