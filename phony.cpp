#include <stdio.h>
#include <math.h>

#define P 2961
#define N 27000

int s[P];

int sieve()
{
  char prime[N+1];
  int i,j;
  for(i=0;i<=N;++i) prime[i]=1;

  int limit=sqrt(N);
  for(i=2;i<=limit;++i)
  {
    for(j=i*i;j<=N;j+=i)
      prime[j]=0;
  }

  for(i=2,j=0;i<N;++i)
    if(prime[i]) {s[j]=i;++j;}
}



int main()
{
  sieve();
  return 0;
}
