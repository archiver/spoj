#include <stdio.h>

int power[10];
int mult[10][10];

void init()
{
  int i,j;
  for(i=0;i<10;++i)
    power[i]=(i*i)%10;
  for(i=0;i<10;++i)
    for(j=0;j<10;++j)
      mult[i][j]=(i*j)%10;
}

int E(int a, int b)
{
   if(b==0) return 1;
   if(a==0) return 0;
   if(b%2)
     return mult[power[E(a,b/2)]][a];
   return power[E(a,b/2)];
}

int main()
{
  int a,b;
  int n;
  init();
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d %d",&a,&b);
    printf("%d\n",E(a%10,b));
  }
  return 0;
}


