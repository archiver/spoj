#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define N 100000000
#define SN    10000
#define P   7000000
#define SP     1250

int sieve[P];
unsigned int bools[((N+SN)>>5)+1];

int small_sieve()
{
  //do not understand how here vs global affects in wierd manners!

  int i,j;
  int limit=sqrt(SN)+1; 

  for(i=3;i<limit;i+=2)
  {
    if((bools[i>>5] & (1<<(i&31))))
      for(j=i*i;j<SN;j+=(i<<1))
	bools[j>>5]= (bools[j>>5] & ~(1<<(j&31)));
  }

  sieve[0]=2;
  bools[0]=(bools[0] & (~3)); //0 & 1 are not primes
  for(i=3,j=1;i<SN;i+=2)
  {
    if(bools[i>>5] & (1<<(i&31)))
    {
      sieve[j]=i;
      j+=1;
    }
  }

  return j;
}

void segmented_sieve()
{
  int i,j;
  int start=SN+1,end=SN+N;

  for(i=0;i<=(end>>5);++i) bools[i]=UINT_MAX;

  int cnt=small_sieve();
  int pos, epos, val;

  for(epos=start+SN;epos<end;epos+=SN)
  {
    start=epos-SN;
    for(i=1;i<cnt;++i)
    {
      val=sieve[i];
      if(val*val>epos) break;

      pos=start+(val+(-start)%val)%val;
      pos=pos%2?pos:pos+val;
      for(j=pos;j<epos;j+=(val<<1))
	bools[j>>5] = (bools[j>>5] & (~(1<<(j&31))));
    }
  }

  for(i=SN+1;i<N;i+=2)
  {
    if(bools[i>>5] & (1<<(i&31)))
    {
      sieve[cnt]=i;
      cnt+=1;
    }
  }
}

int main()
{ 
  segmented_sieve();

  int t,k,i;
  scanf("%d",&t);
  for(i=0;i<t;++i)
  {
    scanf("%d",&k);
    printf("%d\n",sieve[k-1]);
  }

  return 0;
}
