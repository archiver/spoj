#include <stdio.h>
#include <string.h>

#define N 100000
#define S 26
#define PRIME 1000000007

int process(char inp[N])
{
  int alpha[S];
  memset(alpha,0,sizeof(int)*S);

  for(;*inp;++inp)
    alpha[*inp-'A']+=1;

  int prod=1,i=0;
  for(i=0;i<S;++i)
    prod=(prod*(alpha[i]+1))%PRIME;
  return prod;
}

int main()
{
  int t,i;
  char input[N];

  scanf("%d\n",&t);
  for(i=0;i<t;++i)
  {
    scanf("%s",input);
    printf("%d\n",process(input));
  }
  return 0;
}
