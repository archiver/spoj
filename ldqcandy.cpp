#include <stdio.h>
typedef unsigned long long ull;
#define SL(n) scanf("%llu",&n)
#define SI(n) scanf("%d",&n)

const ull b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000, 0x7FFFFFFF00000000LL};
const ull S[] = {1, 2, 4, 8, 16, 32};

inline int hbit(ull v)
{
   int i;
   register unsigned int r = 0;
   for (i = 5; i >= 0; i--)
   {
      if (v & b[i])
      {
	 v >>= S[i];
	 r |= S[i];
      }
   }
   return r;
}


void solve(ull& n)
{
   int h=hbit(n)+1;
   int l=hbit(n^(n&(n-1)));
   printf("%llu %d\n",1LL<<h,(h-l));
}

int main()
{
   int t;
   ull n;

   SI(t);
   while(t--)
   {
      SL(n);
      if(0==(n&(n-1))) 
	 printf("%llu 0\n",n);
      else
	 solve(n);
   }
   return 0;
}
