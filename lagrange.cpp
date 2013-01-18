#include <stdio.h>

const int N = (1<<15);
int sums[N+1];
int squares[N+1];

void init()
{
  int i,j;
  for(i=0;i<=N;++i)
   squares[i]=i*i;

  sums[0]=1;
  for(i=1;i<=N;++i)
  {
    printf("%d ",i);
    for(j=squares[i];j<=N;++j)
      sums[j]+=sums[j-squares[i]]; 
  } 
  return;     
}

int main()
{
  init();
  return 0;
} 
