#include <stdio.h>
#define N 32

int T[N];
int S[N];

void init()
{
  T[0]=1;
  S[0]=1;
  
  int i;
  for(i=2;i<N;i+=2)
  {
    T[i]=T[i-2]+2*S[i-2];
    S[i]=S[i-2]+T[i];
  }
}

int main()
{
  init();
  int n;
  while(1)
  {
    scanf("%d",&n);
    if(n==-1) break;
    printf("%d\n",T[n]);
  }
  return 0;
}
