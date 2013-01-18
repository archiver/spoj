#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

vvi stones;
vvi paths;
vvb visited;
int h,w;

void print(vvi &arr)
{
  for(int i=0;i<h;++i)
  {
    for(int j=0;j<w;++j)
      printf("%*d",4,arr[i][j]);
    printf("\n");
  }
  printf("\n\n");
}

int populate(int i, int j)
{
   if(i>=h || j<0 || j>=w) return 0;
   if(visited[i][j]) return paths[i][j];

   visited[i][j]=true;
   int ldiag=populate(i+1,j-1);
   int down=populate(i+1,j);
   int rdiag=populate(i+1,j+1);

   int m=ldiag;
   m=(down>m)?down:m;
   m=(rdiag>m)?rdiag:m;

   paths[i][j]=stones[i][j]+m;
   return paths[i][j];
}

int optimal()
{
  paths.clear();
  visited.clear();

  paths.insert(paths.begin(),h,vi(w,0));
  visited.insert(visited.begin(),h,vb(w,false));
  
  for(int i=0;i<w;++i)
    populate(0,i);
  
  int m=paths[0][0];
  for(int i=1;i<w;++i)
    if(paths[0][i]>m) m=paths[0][i];
  return m;
}

int main()
{
  int t;
  scanf("%d",&t);

  for(int i=0;i<t;++i)
  {
    scanf("%d %d",&h,&w);
    stones.clear();
    stones.insert(stones.begin(),h,vi(w,0));
    for(int i=0;i<h;++i)
      for(int j=0;j<w;++j)
        scanf("%d",&stones[i][j]);
    cout<< optimal() <<endl;
  }
  return 0;
}
