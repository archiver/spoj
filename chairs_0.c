#include <stdio.h>

#define N 1000
#define PRIME 1000000003

typedef unsigned int uint;

uint L[N+1][N+1];

void calculate(int n)
{
   int i,j,t;

   for(i=1;i<=n;++i)
      L[i][1]= (uint) i;

   for(i=1;i<=n;++i)
   {
      for(j=2;i>=j;++j)
      {
	 for(t=i-2;t>=j-1;--t)
	    L[i][j]=(L[i][j]+L[t][j-1])%PRIME;
      }
   }
}


int main()
{
   int n,k;
   scanf("%d %d",&n,&k);
   if(1==n && 1==k) {printf("1\n"); return 0;}
   if(k<<1 > n) {printf("0\n"); return 0;}

   calculate(n);

   //problem says n>=4
   uint res=L[n][k];
   res=(res+L[n-3][k-1])%PRIME;
   res=(res+(PRIME-L[n-2][k-1])%PRIME)%PRIME;
   printf("%d\n",res);
   return 0;
}
