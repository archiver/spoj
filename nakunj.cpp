#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef queue<ii> qii;

int moves[][8]={{-1, 1,-1,1,-2,-2, 2,2},
                {-2,-2, 2,2,-1, 1,-1,1}};

bool visited[8][8];
ii parent[8][8];

int bfs(ii start, ii end)
{
  ii null(-1,-1);
  int i,j;

  for(i=0;i<8;++i)
  {
    for(j=0;j<8;++j)
    {
      visited[i][j]=false;
      parent[i][j]=null;
    }
  }

  visited[start.first][start.second]=true;

  qii Q;
  int ni,nj;
  ii node,t;

  Q.push(start);

  while(!Q.empty())
  {
    t=Q.front();
    Q.pop();
    for(i=0;i<8;++i)
    {
      ni=t.first+moves[0][i];
      nj=t.second+moves[1][i];
      if(ni>=0 && ni<8 && nj>=0 && nj<8 && !visited[ni][nj])
      {
        visited[ni][nj]=true;
	parent[ni][nj]=t;
	node=ii(ni,nj);
	Q.push(node);
	if(node==end) break;
      }
    }
  }

  node=end;
  int cnt=0;
  while(node!=null)
  {
    node=parent[node.first][node.second];
    cnt+=1;
  }

  return (cnt-1);
}

int main()
{
  int t;
  char left[3],right[3];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s %s",left,right);
    printf("%d\n",bfs(ii(left[1]-'1',left[0]-'a'),ii(right[1]-'1',right[0]-'a')));
  }
  return 0;
}
