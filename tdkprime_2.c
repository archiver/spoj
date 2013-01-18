#include <stdio.h>
#include <limits.h>

#define N 87000000
#define P  5100000

unsigned int prime[(N>>5)+1];
unsigned int primes[P];

int sieve()
{
   int i,j;

   for(i=0;i<(N>>5)+1;++i) prime[i]=UINT_MAX;

   for(i=3;i*i<N;i+=2)
   {
      if(prime[i>>5] & 1<<(i&31))
      {
	 for(j=i*i;j<N;j+=i<<1)
	    prime[j>>5]=(prime[j>>5]&(~(1<<(j&31))));
      }
   }   
}

int main()
{
   sieve();

   int i,j;
   primes[0]=2;
   for(i=3,j=0;i<N;i+=2)
   {
     if(prime[i>>5] & 1<<(i&31))
     {
	j+=1;
	primes[j]=i;
     }
   }

   int t,k;
   scanf("%d",&t);
   for(i=0;i<t;++i)
   {
     scanf("%d",&k);
     printf("%d\n",primes[k-1]);
   }
   return 0;
}
