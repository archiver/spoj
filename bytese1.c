#include <stdio.h>
#include <limits.h>

#define cond(x,y) (x && !y)
#define read(i,j) (prev[i][j]==INT_MAX?paths(i,j):prev[i][j])
#define min(x,y) x<y?x:y
#define si(i) scanf("%d",&i)
#define TRUE 1
#define FALSE 0

char vis[100][100];
int prev[100][100];
int arr[100][100];
int n,m;
int di,dj;

void allocate()
{
   int i,j;
   for(i=0;i<n;++i)
   {
     for(j=0;j<m;++j) 
     {
        si(arr[i][j]);
        prev[i][j]=INT_MAX;
        vis[i][j]=FALSE;
     }
   }
}

void print(int (*array)[100])
{
  int i,j;
  for(i=0;i<n;++i)
  {
    for(j=0;j<m;++j)
      printf("%d ",array[i][j]);
    printf("\n");
  }
  printf("\n");
}

int paths(int i, int j)
{

  vis[i][j]=TRUE;
  int left=cond(i>0,vis[i-1][j])?read(i-1,j):INT_MAX;
  int right=cond(i<n-1, vis[i+1][j])?read(i+1,j):INT_MAX;
  int top=cond(j>0, vis[i][j-1])?read(i,j-1):INT_MAX;
  int bottom=cond(j<m-1, vis[i][j+1])?read(i,j+1):INT_MAX;
  vis[i][j]=FALSE;

  int buf=min(left,right);
  buf=min(buf,top);
  buf=min(buf,bottom);
  prev[i][j]=(buf==INT_MAX?INT_MAX:buf+arr[i][j]);
  return prev[i][j];
}


void solve(int T)
{
  prev[di][dj]=arr[di][dj];
  int res=paths(0,0);
  if(prev[0][0]<=T)
  {
    printf("YES\n");
    printf("%d\n",T-prev[0][0]);
  }
  else
    printf("NO\n");
}

int main()
{
  int cases;
  int T;

  si(cases);
  int i;
  for(i=0;i<cases;++i)
  {
    si(n);
    si(m);
    allocate();
    si(di); si(dj); si(T);
    di-=1;
    dj-=1;
    solve(T);
  }
  return 0;
}
