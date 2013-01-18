#include <stdio.h>
#include <string.h>
typedef long long ll;

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

int E(int a,  ll b)
{
   if(a==0) return 0;
   if(b==0) return 1;
   if(b&1)
     return mult[power[E(a,b>>1)]][a];
   return power[E(a,b>>1)];
}

int main()
{
  init();
  char* ainp=new char[1001];

  int a,n;
  ll b;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%s %lld",ainp,&b);
    a=ainp[strlen(ainp)-1]-'0';
    printf("%d\n",E(a,b));
  }
  return 0;
}
