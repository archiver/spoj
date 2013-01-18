#include <stdio.h>

#define N 2000
#define MAX(a,b) (a)>(b)?(a):(b)

int T[N]; //treat pack
int C[N]; //cumulative sum
int S[N][N]; //dp array
int n;


void init()
{
  if(0==n) return;

  C[0]=T[0];
  for(int i=1;i<n;++i) 
    C[i]=C[i-1]+T[i];
}

int value(int i,int j)
{
  if(0==i) return C[j];
  else return C[j]-C[i-1];
}

int solve()
{
  if(0==n) return 0;
  int i,j,val;
  init();
  for(i=n-1;i>=0;--i)
  {
    S[i][i]=T[i];
    for(j=i+1;j<n;++j)
      S[i][j]=MAX(T[i]+S[i+1][j]+value(i+1,j), T[j]+S[i][j-1]+value(i,j-1));
  }
  return S[0][n-1];
}

int main()
{
   scanf("%d\n",&n);
   for(int i=0;i<n;++i)
     scanf("%d",&T[i]);
   printf("%d\n",solve());
   return 0;
}
