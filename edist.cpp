#include <stdio.h>
#include <string.h>

#define N 4001

char first[N];
char second[N];
int D[N][N];

inline int min(int a,int b)
{
  return a<b?a:b;  
}

int dist()
{
  int n=strlen(first),m=strlen(second);
  int i,j;
  for(i=n;i>=0;--i)
  {
    for(j=m;j>=0;--j)
    {
      if(i==n) { D[i][j]=m-j; continue; }
      if(j==m) { D[i][j]=n-i; continue; }

      D[i][j]=D[i+1][j+1]+(first[i]==second[j]?0:1);
      D[i][j]=min(D[i][j], D[i+1][j]+1);
      D[i][j]=min(D[i][j], D[i][j+1]+1);
    }
  }

  return D[0][0];
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",&first);
    scanf("%s",&second);
    printf("%d\n",dist());
  }
  return 0;
}
