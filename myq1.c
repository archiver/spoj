#include <stdio.h>

char dir[2][5];
char name[2][5];

void init()
{
  dir[0][0]='L'; dir[1][0]='R';
  dir[0][1]='L'; dir[1][1]='R';
  dir[0][2]='R'; dir[1][2]='R';
  dir[0][3]='R'; dir[1][3]='L';
  dir[0][4]='R'; dir[1][4]='L';

  name[0][0]='W'; name[1][0]='W';
  name[0][1]='A'; name[1][1]='M';
  name[0][2]='A'; name[1][2]='A';
  name[0][3]='M'; name[1][3]='A';
  name[0][4]='W'; name[1][4]='W';

}

void position(unsigned int n)
{
  unsigned int row=(n-2)/5;
  
  unsigned int type=row&1; //0 left-right, 1 right-left
  unsigned int offset=n-(row<<2)-row-2;

  printf("%d %c %c\n",row+1,name[type][offset],dir[type][offset]);
}

int main()
{
  unsigned int t,i=0;
  unsigned int n=0;
  init();
  scanf("%d",&t);
  for(i=0;i<t;++i)
  {
    scanf("%d",&n);
    (1==n)?printf("poor conductor\n"):position(n);
  }
  return 0;
}
