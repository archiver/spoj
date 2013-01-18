#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

int gcd(int a, int b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}

int main()
{
  int i,j;
  int n,num;
  int a,b;
  char name[4];
  const int part = (1<<16)-1;

  while(true)
  {
    scanf("%d",&n);
    if(!n) break;

    int prod=1;
    for(i=0;i<n;++i)
    {
      scanf("%s %d",&name,&num);
      if(strcmp(name,"MUL")==0)
        prod=(prod*num)&part;
    }

    if(prod)
    {
      a=65536%prod; b=prod;
      int den = (a>b)?gcd(a,b):gcd(b,a);
      printf("%d\n",65536/den);
    }
    else
      printf("1\n");
  }
  return 0;
}
