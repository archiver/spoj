#include <stdio.h>
typedef unsigned long long ull;

const ull b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000, 0xFFFFFFFF00000000};
const unsigned int S[] = {1, 2, 4, 8, 16, 32};

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
   return r+1;
}


int main()
{
   printf("%d\n",hbit(9));

   return 0;
}
