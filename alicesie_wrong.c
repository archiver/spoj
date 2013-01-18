#include <stdio.h>
#include <limits.h>

#define N 1000001
#define P   79000

unsigned int prime[(N>>5)+1];
unsigned int primes[P];

int next(int s, int e, int val)
{
  int m=(s+e)/2;
  if(primes[m]==val) return m+1;
  if(s==e)
    return primes[m]>val?m:m+1;
  if(primes[m]>val) return next(s,m,val);
  else return next(m+1,e,val);
}

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
   
   primes[0]=2;
   for(i=3,j=0;i<N;i+=2)
   {
     if(prime[i>>5] & 1<<(i&31))
     {
	j+=1;
	primes[j]=i;
     }
   }
   
   return j;
}


int main()
{
   int cnt = sieve();
   int t,n;
   scanf("%d",&t);

   while(t--)
   {
     scanf("%d",&n);
     printf("%d\n",next(0,cnt,n));
   }

   return 0;
}
