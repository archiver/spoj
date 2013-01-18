#include <stdio.h>

#define N 1000
#define PRIME 1000000003

typedef unsigned int uint;

uint L[N+1][N+1];
uint A[N+1][N+1];

void calculate(int n)
{
   int i,j,t;

   L[1][1]=1;
   A[1][1]=1;
   for(i=2;i<=n;++i)
   {
      L[i][1]= i;
      A[i][1]= (A[i-1][1]+i)%PRIME;
   }

   for(i=1;i<=n;++i)
   {
      for(j=2;j<=i;++j)
      {
	 A[i][j]=(A[i][j]+A[i-1][j])%PRIME;

         if(i-2>=j-1)
	 {
  	   L[i][j]=(A[i-2][j-1]+L[i][j])%PRIME;
   	   A[i][j]=(A[i][j]+L[i][j])%PRIME;
	 }
      }
   }
}


int main()
{
   int n,k;
   scanf("%d %d",&n,&k);

   //problem says n>=4
   calculate(n);

   uint res=L[n][k];
   res=(res+L[n-3][k-1])%PRIME;
   res=(res+(PRIME-L[n-2][k-1])%PRIME)%PRIME;
   printf("%d\n",res);
   return 0;
}

