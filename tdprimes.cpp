#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define N 100000000
#define SN    10000
#define SP     1250

int sieve[SP];
unsigned int bools[(N>>5)+1];

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
  int start=SN;
  start= (start%2)?start:start+1;

  for(i=0;i<=(N>>5);++i) bools[i]=UINT_MAX;

  int cnt=small_sieve();
  int pos, val;

  for(i=1;i<cnt;++i)
  {
    val=sieve[i];
    pos=start+(val+(-start)%val)%val;
    for(j=pos;j<N;j+=val)
      bools[j>>5] = (bools[j>>5] & (~(1<<(j&31))));
  }

  int total=1;
  printf("2\n");
  for(i=3;i<N;i+=2)
  {
    if(bools[i>>5] & (1<<(i&31)))
    {
      total+=1;
      if(total%100==1) printf("%d\n",i);
    }
  }
}

int main()
{ 
  segmented_sieve();
  return 0;
}
