#include <stdio.h>
#include <limits.h>

#define N 1000
#define P  168

#define T 1000000
char dual[T];
int divisors[T];

unsigned int prime[(N>>5)+1];
int primes[P];

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
   j=0;
   for(i=3;i<N;i+=2)
   {
     if(prime[i>>5] & 1<<(i&31))
     {
	j+=1;
	primes[j]=i;
     }
   }
}

void solve()
{
  int i,j;
  int var,prod,cnt,num;
  
  divisors[1]=1;
  dual[1]=0;
 
  for(i=2;i<T;++i)
  {
    var=0; prod=1;

    for(j=0,num=i;num && j<P;++j)
    {
      cnt=1;
      while(num && !(num%primes[j])) 
      {
        num=num/primes[j];
	cnt+=1;
      }
      if(cnt>1) 
      {
        var+=1;
	prod*=cnt;
      }
    }

    if(num>1)
    {
       prod*=2;
       var+=1;
    }

    divisors[i]=prod;
    if(var==2 && prod==4) dual[i]=1;
  }

  j=0;
  for(i=2;i<T;++i)
  {
    if(dual[divisors[i]]) 
    {
      j+=1;
      if(!(j%9))
        printf("%d\n",i);
    }
  }
}

int main()
{
   sieve();
   solve();
   return 0;
}
