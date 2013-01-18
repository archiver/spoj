#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define N 100000000
#define SN    10000
#define SP     1250

int sieve[SP];
unsigned int bools[SN>>5+1];

int small_sieve()
{
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
  printf("2\n");

  for(i=3,j=1;i<SN;i+=2)
  {
    if(bools[i>>5] & (1<<(i&31)))
    {
      sieve[j]=i;
      j+=1;
      if(j%100==1)
	printf("%d\n",i);
    }
  }

  return j;
}

void segmented_sieve()
{
  int i,j;
  int start=SN+1,end=SN+N;

  for(i=0;i<=(SN>>5);++i) bools[i]=UINT_MAX;

  int cnt=small_sieve();
  int epos, val, pos, t;

  for(epos=start+SN;epos<end;epos+=SN)
  {
    for(i=0;i<=(SN>>5);++i) bools[i]=UINT_MAX;

    start=epos-SN;
    for(i=1;i<cnt;++i)
    {
      val=sieve[i];
      if(val*val>epos) break;

      pos=start+(val+(-start)%val)%val;
      pos=pos%2?pos:pos+val;

      for(j=pos;j<epos;j+=(val<<1))
	bools[(j-start)>>5] = (bools[(j-start)>>5] & (~(1<<(j&31))));

      for(t=0;t<SN;t+=2)
      {
	if(bools[t>>5] & (1<<((t+start)&31)))
	{
	  if(cnt%100==1 && (t+start)<N)
	    printf("%d\n",(t+start));
	  cnt+=1;
	}
      }
    }
  }
}

int main()
{ 
  segmented_sieve();
  return 0;
}
