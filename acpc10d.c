#include <stdio.h>

#define N 100000

int g[N][3];
int c[N][3];
int n;

inline int MIN(int a, int b)
{
  return a<=b?a:b;
}

void print(int arr[N][3])
{
  int i,j;
  for(i=0;i<n;++i)
  {
    for(j=0;j<3;++j)
      printf("%d ",arr[i][j]);
    printf("\n");
  }
}

int calculate()
{
  c[n-1][0]=g[n-1][0]+g[n-1][1];
  c[n-1][1]=g[n-1][1];
  c[n-1][2]=1000000;

  int i=n-2;
  for(;i>=0;--i)
  {
    c[i][2]=MIN(c[i+1][1],c[i+1][2])+g[i][2];

    c[i][1]=MIN(c[i+1][0],c[i+1][2]);
    c[i][1]=MIN(c[i][1],c[i+1][1]);
    c[i][1]=MIN(c[i][1],c[i][2])+g[i][1];

    c[i][0]=MIN(c[i+1][0],c[i+1][1]);
    c[i][0]=MIN(c[i][0],c[i][1])+g[i][0];
  }

  return c[0][1];
}

int main()
{
  int t=1;
  int i,j;
  while(1)
  {
    scanf("%d",&n);
    if(!n) break;
    for(i=0;i<n;++i)
      for(j=0;j<3;++j)
        scanf("%d",&g[i][j]);
    printf("%d. %d\n",t,calculate());
    t+=1;
  }
  return 0;
}
