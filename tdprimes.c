#include <stdio.h>
#include <limits.h>

#define N 100000000

unsigned int prime[(N>>5)+1];

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
   printf("2\n");
   for(i=3,j=0;i<N;i+=2)
   {
     if(prime[i>>5] & 1<<(i&31))
     {
	j+=1;
	if(!(j%100)) 
	  printf("%d\n",i);
     }
   }
   return 0;
}
