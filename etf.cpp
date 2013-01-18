#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

#define N 2000
#define P 1000

int primes[P];

int init()
{
  bool pmask[N];
  int i,j;
  int limit=sqrt(N)+1;

  for(i=0;i<N;++i) pmask[i]=true;
  primes[0]=2;

  for(i=3;i<limit;++i)
  {
    if(pmask[i])
    {
      for(j=i*i;j<N;j+=(i+i))
       pmask[j]=false;
    }
  }
  
  j=1;
  for(i=3;i<N;i+=2)
  {
    if(pmask[i])
    {
      primes[j]=i;
      j+=1;
    }
  }
  return j;
}

ull totient(int n, int cnt)
{
  if(1==n) return 1;
  int num=n;
  ull res=1L;
  bool gprime=true;

  for(int t=0;t<cnt;++t)
  {
    if(num%primes[t]==0)
    {
      gprime=false;
      while(num%primes[t]==0)
      {
        num/=primes[t];
	res*=primes[t];
      }
      res/=primes[t];
      res*=(primes[t]-1);
    }
  }

  if(gprime) return n-1;
  if(num>1) res*=(num-1); //forgot this crucial step repeatedly
  return res;
}

int main()
{
  int cnt = init();
  int t,val;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&val);
    printf("%llu\n",totient(val,cnt));
  }
  return 0;
}
