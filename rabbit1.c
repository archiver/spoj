#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;


void multiply(ull F[2][2], ull M[2][2], ull modulo)
{
   ull x =  ((F[0][0]*M[0][0])&modulo) + ((F[0][1]*M[1][0])&modulo);
   ull y =  ((F[0][0]*M[0][1])&modulo) + ((F[0][1]*M[1][1])&modulo);
   ull z =  ((F[1][0]*M[0][0])&modulo) + ((F[1][1]*M[1][0])&modulo);
   ull w =  ((F[1][0]*M[0][1])&modulo) + ((F[1][1]*M[1][1])&modulo);

   F[0][0] = x&modulo;
   F[0][1] = y&modulo;
   F[1][0] = z&modulo;
   F[1][1] = w&modulo;
}

void power(ull F[2][2], ull n, ull modulo)
{
   if( n == 0 || n == 1)
      return;

   ull M[2][2] = {{1L,1L},{1L,0L}};

   power(F, n/2, modulo);
   multiply(F, F, modulo);

   if( n%2 != 0 )
      multiply(F, M, modulo);
}

ull spill(ull n, int m)
{
   if(!n) return 0;
   ull modulo = (1L<<m)-1;
   ull F[2][2] = {{1L,1L},{1L,0L}};
   power(F, n,modulo);
   return F[0][0];
}

int main()
{
   int t,i;
   ull n;
   int m;
   scanf("%d",&t);

   for(i=0;i<t;++i)
   {
      scanf("%lld %d",&n,&m);
      printf("%lld\n",spill(n,m));
   }
   return 0;
}
