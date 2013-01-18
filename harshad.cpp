#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include <algorithm>
using namespace std;

#define N   1000000
#define SN     1000
#define P     81000
#define SP      200
#define DP     7000

int sieve[P];
unsigned int bools[SN>>5+1];

int sums[N+1];
int dup_sums[N+1];

int dev[DP];

bool search(int s, int e, int val)
{
   int m=(s+e)/2;
   if(dup_sums[m]==val) return true;
   if(s==e) return false;
   if(dup_sums[m]>val) return search(s,m,val);
   else return search(m+1,e,val);
}

int bisect(int s, int e, int val)
{
   int m=(s+e)/2;
   if(dev[m]==val) return m;
   if(s==e)
     return dev[m]>val?m:m+1;
   if(dev[m]>val) return bisect(s,m,val);
   else return bisect(m+1,e,val);
}

int compute(int count)
{
   int i,num;
   for(i=0;i<=N;++i)
   {
     num=i;
     sums[i]=num;
     for(;num;num/=10) sums[i]+=(num%10);
     dup_sums[i]=sums[i];
   }
   
   sort(dup_sums,dup_sums+N+1); //sort it for searching

   int j=0;
   for(i=0;i<count;++i)
   {
      if(!search(0,N,sieve[i]))
      {
        dev[j]=sieve[i];
	j+=1;
      }
   }

   return j;
}

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


  bools[0]=(bools[0] & (~3)); //0 & 1 are not primes
  sieve[0]=2;

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

int segmented_sieve()
{
  int i,j;
  int start=SN+1,end=SN+N;

  for(i=0;i<=(SN>>5);++i) bools[i]=UINT_MAX;

  int cnt=small_sieve();
  int pcount=cnt;
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
    }
    
    for(t=0;t<SN;t+=2)
    {
      if(bools[t>>5] & (1<<((t+start)&31)))
      {
	  sieve[pcount]=t+start;
	  pcount+=1;
      }
    }
  }

  return pcount;
}

int calculate(int a, int b, int count)
{
  int start=bisect(0,count-1,a);
  int end=bisect(0,count-1,b);
  if(end<count && dev[end]==b) end+=1;
  return end-start;
}

int main()
{ 
  int count = segmented_sieve();
  int devcount = compute(count);

  int q,a,b;
  scanf("%d",&q);
  
  while(q--)
  {
    scanf("%d %d",&a,&b);
    printf("%d\n",calculate(a,b,devcount));
  }
  return 0;
}
