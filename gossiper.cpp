#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define S 500
#define N 2100
#define M 12000

typedef pair<int,int> ii;
map<string,int> nodes;
ii edges[M];
int check[N][N];

bool solve(int n,int m)
{
  int a,b,i,j;

  for(i=0;i<n;++i)
  {
    for(j=0;j<n;++j)
      check[i][j]=0;
    check[i][i]=1;
  }

  for(i=0;i<m;++i)
  {
     a=edges[i].first;
     b=edges[i].second;
     
     for(j=0;j<n;++j)
     {
       check[a][j] = check[a][j]|check[b][j];
       check[b][j] = check[a][j];
     }
  }

  for(int i=0;i<n;++i)
  {
     for(int j=0;j<n;++j)
     {
       if(!check[i][j]) return false;
     }
  }


  return true;
}

int main()
{
  int n,m;
  char name[S];
  char left[S], right[S];
  while(true)
  {
    scanf("%d %d",&n,&m);
    if(!n && !m) break;

    nodes.clear();
    for(int i=0;i<n;++i)
    {
      scanf("%s",&name);
      nodes[string(name)]=i;
    }
    for(int j=0;j<m;++j)
    {
       scanf("%s %s",&left,&right);
       edges[j]=ii(nodes[string(left)],nodes[string(right)]);
    }
    if(solve(n,m))
      printf("YES\n");
    else 
      printf("NO\n");
  }
  return 0;
}
