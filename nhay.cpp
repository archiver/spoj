#include <stdio.h>
#include <stdlib.h>

void pattern(char *p, int* b, int m)
{
  int i=0,j=-1;
  b[i]=j;
  while(i<m)
  {
    while(j>=0 && p[i]!=p[j]) j=b[j];
    i+=1;j+=1;
    b[i]=j;
  }
}

int find()
{
  int m;

  if(scanf("%d\n",&m)==EOF) return 0;
  
  int *b=new int[m+1];
  char *p=new char[m];

  scanf("%s",p);
  pattern(p,b,m);

  int i=0,j=0;
  char c;
  
  c=getchar(); //read the extra line
  while((c=getchar())!='\n')
  {
    while(j>=0 && c!=p[j]) j=b[j];
    i+=1;j+=1;
    if(j==m)
    {
      printf("%d\n",i-j);
      j=b[j];
    }
  }

  printf("\n");
  return 1;
}

int main()
{
  int call;
  do 
  {
    call=find();
  }while(call);

  return 0;
}
