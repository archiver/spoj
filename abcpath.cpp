#include <stdio.h>

#define N 50
char grid[N][N];
bool visited[N][N];
int dir[8];
int n,m;

void init()
{
  int i,j;
  for(i=0;i<n;++i)
    for(j=0;j<m;++j)
      visited[i][j]=false;
}

int maximum()
{
  int i=0,ma=dir[0];
  for(i=1;i<8;++i)
    if(dir[i]>ma) ma=dir[i];
  return ma;
}

int solve(int i, int j, char cur)
{
  if(i<0 || i>=n || j<0 || j>=m || visited[i][j]) return 0;
  if(grid[i][j]!=cur+1) return 0;
  visited[i][j]=true;
  dir[0] = solve(i,j-1,grid[i][j]); //west
  dir[1] = solve(i,j+1,grid[i][j]); //east
  dir[2] = solve(i+1,j,grid[i][j]); //south
  dir[3] = solve(i-1,j,grid[i][j]); //north
  dir[4] = solve(i-1,j-1,grid[i][j]); //north west
  dir[5] = solve(i-1,j+1,grid[i][j]); //north east
  dir[6] = solve(i+1,j-1,grid[i][j]); //south west
  dir[7] = solve(i+1,j+1,grid[i][j]); //south east
  visited[i][j]=false;
  return 1+maximum();
}

int solveUtil()
{
  int i=0,j=0;
  visited[i][j]=true;
  dir[0] = solve(i,j-1,grid[i][j]); //west
  dir[1] = solve(i,j+1,grid[i][j]); //east
  dir[2] = solve(i+1,j,grid[i][j]); //south
  dir[3] = solve(i-1,j,grid[i][j]); //north
  dir[4] = solve(i-1,j-1,grid[i][j]); //north west
  dir[5] = solve(i-1,j+1,grid[i][j]); //north east
  dir[6] = solve(i+1,j-1,grid[i][j]); //south west
  dir[7] = solve(i+1,j+1,grid[i][j]); //south east

  return 1+maximum();
}

int main()
{
  int i=0,cas=0;
  while(scanf("%d %d",&n,&m) && n>0 && m>0)
  {
    init();
    for(i=0;i<n;++i)
      scanf("%s",grid[i]);
    cas+=1;
    printf("Case %d: %d\n",cas,solveUtil());
  }
  return 0;
}
