#include <stdio.h>

using namespace std;
#define N 1001
#define PRIME 1000000007

typedef unsigned long long ull;

ull comb[N][N];
ull sumb[N][N];

void compute()
{
  int i,j;
 
  for(j=0;j<N;++j)
  {
    for(i=0;i<j;++i)
      sumb[i][j]=1L;
  }
  
  for(j=1;j<N;++j) //value of k
  {
    for(i=j;i<N;++i) //value of n
    {
      comb[i][j]= sumb[i-j][j];
      sumb[i][j]=(sumb[i-1][j]+comb[i][j])%PRIME;
    }
  }
}

int main()
{
  compute();
  return 0;
}
