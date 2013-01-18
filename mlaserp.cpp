#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef queue<ii> qii;

#define N 100
char g[N][N];
ii parent[N][N];
ii neigh[] = {ii(-1,0),ii(1,0),ii(0,-1),ii(0,1)};

int solve(int n,int m)
{
  ii cur;
  ii cs[2];
  qii Q;
  int i,j;
  int x,y,h,pos=0;

  const ii null=ii(n,m);
  for(i=0;i<n;++i)
  {
    for(j=0;j<m;++j)
    {
      if(g[i][j]=='C')
      {
       cs[pos]=ii(i,j); pos+=1;
      }
      parent[i][j]=null;
    }
  }

  parent[cs[0].first][cs[0].second]=ii(0,0);

  Q.push(cs[0]);
  while(!Q.empty())
  {
    cur=Q.front();
    Q.pop();

    for(h=0;h<4;++h)
    {
      x=cur.first+neigh[h].first;
      y=cur.second+neigh[h].second;
      if(x>=0 && x<n && y>=0 && y<m && g[x][y]!='*' && parent[x][y]==null)
      {
         parent[x][y]=cur;
	 Q.push(ii(x,y));
      }
    }
  }

  
  return 0;
}

int main()
{
  int n,m,i,j;
  scanf("%d %d",&m,&n);
  for(i=0;i<n;++i)
     scanf("%s",&g[i]);
  printf("%d\n",solve(n,m));
  return 0;
}
