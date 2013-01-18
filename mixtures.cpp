#include <stdio.h>
#define INF 100000000
#define N 101
int C[N];
int S[N];
int A[N][N];
int n;

void init()
{
  int i;
  S[0]=C[0];
  for(i=1;i<n;++i)
    S[i]=(S[i-1]+C[i])%100;
}

int value(int i, int j)
{
  if(0==i) return (S[j]%100+100)%100;
  else return ((S[j]-S[i-1])%100+100)%100;
}

int solve()
{
  int i,j,k,val;
  init();
  for(j=0;j<n;++j)
  {
    for(i=j;i>=0;--i)
    {
      if(i==j) {A[i][j]=0; continue;}
      A[i][j]=INF;
      for(k=i;k+1<=j;++k)
      {
         val = A[i][k]+A[k+1][j]+value(i,k)*value(k+1,j);
	 if(val<A[i][j])
	   A[i][j]=val;
      }
    }
  }
  return A[0][n-1];
}


int main()
{
  while(scanf("%d",&n)!=EOF)
  {
    for(int i=0;i<n;++i) scanf("%d",&C[i]);
    printf("%d\n",solve());
  }
  return 0;
}
