#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

#define S 182
#define SI(n) scanf("%d",&n)

char bitmap[S][S];
int calc[S][S];
int visited[S][S];
int neigh[4];
int n, m;

int traverse(int i, int j)
{
  if(i<0 || i>=n || j<0 || j>=m) return INT_MAX;
  if(visited[i][j]) return calc[i][j];

  visited[i][j]=1;
  neigh[0]=traverse(i,j-1);
  neigh[1]=traverse(i,j+1);
  neigh[2]=traverse(i-1,j);
  neigh[3]=traverse(i+1,j);
  visited[i][j]=0;

  calc[i][j]=*min_element(neigh,neigh+4)+1;

  return calc[i][j];
}

void solve()
{
  SI(n); SI(m);
  int i,j;
  for(i=0;i<n;++i)
    scanf("%s",&bitmap[i]);

  for(i=0;i<n;++i)
  {
    for(j=0;j<m;++j)
    {
      if(bitmap[i][j]-'0') { calc[i][j]=0; visited[i][j]=1; }
      else { calc[i][j] = INT_MAX; visited[i][j]=0;}
    }
  }

  traverse(0,0);
  
  for(i=0;i<n;++i)
  {
   for(j=0;j<m;++j)
   {
     printf("%d ",calc[i][j]);
   }
   printf("\n");
  }
}

int main()
{
  int t;
  SI(t);
  while(t--) 
     solve();
  return 0;
}
