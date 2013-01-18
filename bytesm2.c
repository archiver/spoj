#include <stdio.h>

int stones[100][100];
int paths[100][100];
char visited[100][100];
int h,w;

void print(int arr[100][100])
{
  int i,j;
  for(i=0;i<h;++i)
  {
    for(j=0;j<w;++j)
      printf("%*d",4,arr[i][j]);
    printf("\n");
  }
  printf("\n\n");
}

int populate(int i, int j)
{
   if(i>=h || j<0 || j>=w) return 0;
   if(visited[i][j]) return paths[i][j];

   visited[i][j]=1;
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
  int i,j;
  for(i=0;i<h;++i)
    for(j=0;j<w;++j) {paths[i][j]=0; visited[i][j]=0;}
  
  for(i=0;i<w;++i)
    populate(0,i);
  
  int m=paths[0][0];
  for(i=1;i<w;++i)
    if(paths[0][i]>m) m=paths[0][i];
  return m;
}

int main()
{
  int cases;
  scanf("%d",&cases);
  int i,j,t;
  for(t=0;t<cases;++t)
  {
    scanf("%d %d",&h,&w);
    for(i=0;i<h;++i)
      for(j=0;j<w;++j)
        scanf("%d",&stones[i][j]);
    printf("%d\n",optimal());
  }
  return 0;
}
