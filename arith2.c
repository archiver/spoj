#include <stdio.h>

#define SI(n) scanf("%d",&n);
#define SC(c) scanf("%c",&c);

typedef unsigned long long ull;

inline ull operate(ull res, int x, char c)
{
  if(c=='+') return res+x;
  else if(c=='-') return res-x;
  else if(c=='*') return res*x;
  else if(c=='/') return res/x;
}

int main()
{
  int t=0;
  SI(t);

  long long res;
  int x; char c=' ';
  while(t--)
  {
    SI(x);
    c=' ';
    while(c==' ') SC(c);
    if(c=='=')
    {
      printf("%d\n",x);
      continue;
    }

    res=x;
    while(c!='=')
    {
      SI(x);
      res=operate(res,x,c);
      c=' ';
      while(c==' ') SC(c);
    }

    scanf("\n"); //change to next line
    printf("%lld\n",res);
  }

  return 0;
}
