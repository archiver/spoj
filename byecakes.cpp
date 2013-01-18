#include <stdio.h>
#include <math.h>

#define N 4
int A[N];
int B[N];
float C[N];

int solve()
{
  for(int i=0;i<N;++i) 
    C[i]=A[i]*1.0/B[i];

  float ma=C[0];
  for(int i=0;i<N;++i)
    if(C[i]>ma) ma=C[i];

  int c = int(ceil(ma));

  for(int i=0;i<N;++i)
    printf("%d ",B[i]*c-A[i]);
  printf("\n");
}

int main()
{
  while(true)
  {
    scanf("%d %d %d %d",&A[0],&A[1],&A[2],&A[3]);
    scanf("%d %d %d %d",&B[0],&B[1],&B[2],&B[3]);
    if(A[0]==-1 && B[0]==-1) break;
    solve();
  }
  return 0;
}
