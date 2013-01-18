#include <stdio.h>
#include <math.h>

#define N 1001
#define M 1000001

#define P 200

typedef unsigned long long ull;

int primes[P];
int phi[M];
ull phi_sum[M];

void init()
{
  bool pmask[N];
  int i,j;
  int limit=sqrt(N)+1;

  //sieve of erasthosenes
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

  //euler totient function
  phi[1]=1;
  phi_sum[1]=0L;
  int pnum,num,val,t;
  for(i=2;i<M;++i)
  {
    pnum=-1;
    for(t=0;t<j;++t)
      if(i%primes[t] == 0) { pnum=primes[t];break;}
    if(pnum==-1) //it is a prime number > N
      phi[i]=(i-1);
    else
    {
      num=i;
      val=1;
      while(num%pnum==0)
      {
        num/=pnum;
	val*=pnum;
      }
      val/=pnum;
      val*=(pnum-1);
      phi[i]=val*phi[num];
    }

    phi_sum[i]=phi_sum[i-1]+phi[i];
  }
}

int main()
{
  init();
  for(int i=1;i<=1000000;++i)
    printf("%d %d\n",i,phi[i]);
}

/*
int main()
{
  init();
  int t,val;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&val);
    printf("%llu\n",phi_sum[val]);
  }
  return 0;
}
*/
