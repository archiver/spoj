#include <stdio.h>

#define N 10000001
#define P   670000

int vals[N];
int primes[P];
bool prime[N];
int p;

int bisect(int s, int e, int val)
{
  int m=(s+e)/2;
  if(primes[m] ==val) return m;
  if(s==e)
   return primes[m]>val?m:m+1;
  if(primes[m]>val) return bisect(s,m,val);
  else return bisect(m+1,e,val);
}

int bisect_left(int s, int e, int val)
{
  int m=(s+e)/2;
  if(primes[m] ==val) return m+1;
  if(s==e)
   return primes[m]>val?m:m+1;
  if(primes[m]>val) return bisect_left(s,m,val);
  else return bisect_left(m+1,e,val);
}


void init()
{
   int i,j;

   for(i=3;i*i<N;i+=2)
   {
      if(!prime[i])
      {
	 for(j=i*i;j<N;j+=(i+i))
	    prime[j]=true;
      }
   } 
}

void sieves()
{
   init();

   primes[0]=2;
   vals[2]=1;
   int i,j=1,end=2;

   for(i=3;i<N;++i)
   {
      if(i%end)
	 vals[i]=vals[i-1]+1;
      else 
      {
	 vals[i]=vals[i-1];
	 end+=1;
      }

      if(i&1 && !prime[i])
      {
        primes[j]=i;
	j+=1;
      }
   }

   p=j;
}

int solve(int n)
{
   int l=vals[n];
   int low=bisect(0,p-1,n-l+1);
   int high= bisect_left(low,p-1,n);
   return (high-low);
}

int main()
{
   int t,n;
   sieves();

/*   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      printf("%d\n",solve(n));
   }
*/
   return 0;
}
