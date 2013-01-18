#include <stdio.h>
#include <map>
using namespace std;
typedef pair<int,int> ii;

#define S 1000
map<char,ii> dir;
bool visited[S][S];
char state[S][S];

void init()
{
  dir['N']=ii(-1,0);  
  dir['S']=ii(1,0);  

  dir['E']=ii(0,1);  
  dir['W']=ii(0,-1);  
}

inline void mark(int m, int si, int sj)
{
  int i=si,j=sj;
  visited[i][j]=true;
  ii t;
  do
  {
    t=dir[state[i][j]];
    i+=t.first;
    j+=t.second;
    visited[i][j]=true;
  }while(!(si==i && sj==j));
}

int solve(int n, int m)
{
  int cycle=0;
  int s=n*m;
  int i,j;
  for(i=0;i<n;++i)
  {
    for(j=0;j<m;++j)
    {
      if(!visited[i][j])
      {
        mark(m,i,j);
	cycle+=1;
      }
    }   
  }
  return cycle;
}

int main()
{
  int n,m;
  init();
  scanf("%d %d",&n,&m);
  int i,j;
  for(i=0;i<n;++i)
      scanf("%s",&state[i]);

  printf("%d\n",solve(n,m));
  return 0;
}
