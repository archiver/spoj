#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;
#define PRIME 1000000007

void multiply(ull F[2][2], ull M[2][2])
{
   ull x =  (F[0][0]*M[0][0])%PRIME + (F[0][1]*M[1][0])%PRIME;
   ull y =  (F[0][0]*M[0][1])%PRIME + (F[0][1]*M[1][1])%PRIME;
   ull z =  (F[1][0]*M[0][0])%PRIME + (F[1][1]*M[1][0])%PRIME;
   ull w =  (F[1][0]*M[0][1])%PRIME + (F[1][1]*M[1][1])%PRIME;

   F[0][0] = x%PRIME;
   F[0][1] = y%PRIME;
   F[1][0] = z%PRIME;
   F[1][1] = w%PRIME;
}

void power(ull F[2][2], ull n)
{
   if( n == 0 || n == 1)
      return;

   ull M[2][2] = {{1L,1L},{1L,0L}};

   power(F, n/2);
   multiply(F, F);

   if( n%2 != 0 )
      multiply(F, M);
}

ull fib(ull n)
{
   if(!n) return 0;
   ull F[2][2] = {{1L,1L},{1L,0L}};
   power(F, n-1);
   return F[0][0];
}

ull fibosum(ull n, ull m)
{
   ull fm=fib(m+2), fn=fib(n+1);
   return (PRIME+fm-fn)%PRIME;
}

int main()
{
   int t,i;
   ull n,m;
   scanf("%d",&t);

   for(i=0;i<t;++i)
   {
      scanf("%lld %lld",&n,&m);
      printf("%lld\n",fibosum(n,m));
   }
   return 0;
}
