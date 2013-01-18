#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 90000000
#define P 6000000

char prime[N];
int primes[P];

int sieve()
{
   memset(prime,true,sizeof(char)*N);
   int n=sqrt(N);

   int i,j;
   for(i=2;i<=n;++i)
   {
      if(prime[i])
      {
	 for(j=i*i;j<N;j+=i)
	    prime[j]=false;
      }
   }
   
   j=0;
   for(i=2;i<N;++i)
     if(prime[i]) { primes[j]=i;++j;}
}

int main()
{
  sieve();
  int t,k;
  scanf("%d",&t);
  for(int i=0;i<t;++i)
  {
    scanf("%d",&k);
    printf("%d  %d\n",primes[k-1], k);
  }

  return 0;
}
