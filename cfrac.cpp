#include <stdio.h>

void cfrac(int a, int b)
{
  int t;
  
  if(!b) 
  {
    printf("1\n");
    return;
  }

  if(!(a%b))
  {
    printf("%d,",a/b-1);
    cfrac(1,0);
    return;
  }
  else
  {
    printf("%d,",a/b);
    t=a;
    a=b;
    b=t%b;
    cfrac(a,b);
    return;
  }
}

int main()
{
  cfrac(61,60);
  return 0;
}
