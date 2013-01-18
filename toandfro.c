#include <stdio.h>
#include <string.h>
#define N 200
char matrix[N][N];
char visited[N];

void populate(char s[N], int c, int l)
{
  int t=0;
  int i=0,j=0;
  for(t=0;t<l;++i)
  {
    j=0;
    for(;j<c && t<l;++t,++j) 
      matrix[i][j]=s[t];
    ++i;

    j=c-1;
    for(;j>=0 && t<l;++t,--j) 
      matrix[i][j]=s[t];
  }

  for(j=0;j<c;++j)
    for(i=0;i<(l/c);++i)
       printf("%c",matrix[i][j]);
  printf("\n");
}

int main()
{
   char s[N];
   int c,n;
   while(1)
   {
      scanf("%d",&c);
      if(!c) break;

      scanf("%s",&s);
      n=strlen(s);

      populate(s,c,n);
   }
   return 0;
}
