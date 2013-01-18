#include <stdio.h>
#include <string.h>

#define N 1010
char name[N];
int mat[2][2];

inline int min(int a, int b)
{
  return a<b?a:b;
}

int main()
{
  int n,i;

  while((scanf("%s",&name))!=EOF)
  {
    int n=strlen(name);

    mat[0][0]=0;mat[0][1]=0;
    mat[1][0]=0;mat[1][1]=0;

    for(i=0;i<n;i+=2)
    {
      if(name[i]>='A' && name[i]<='Z') //upper case
        mat[0][0]+=1;
      else
        mat[0][1]+=1;
    }

    for(i=1;i<n;i+=2)
    {
      if(name[i]>='A' && name[i]<='Z') //upper case
        mat[1][0]+=1;
      else
        mat[1][1]+=1;
    }

    int left = mat[0][0]+mat[1][1];
    int right = mat[0][1]+mat[1][0];
    printf("%d\n",min(left,right));
  }
  return 0;
}
