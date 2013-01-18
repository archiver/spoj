#include <stdio.h>

#define N 1000
bool isKilled[N];

int main()
{
  int n,i,j;
  while(scanf("%d",&n) && n>0)
  {
    int lastman=0,i=0;
    for(i=0;i<n;++i) isKilled[i]=false;

    i=0;
    while(true)
    {
      if(!isKilled[i])
      {
        lastman=i;
        for(j=(i+1)%n;j!=i && isKilled[j];j=(j+1)%n);
	if(j==i) { lastman=i; break;}
	else { isKilled[j]=true; }
      }
      i=(i+1)%n;
    }
    printf("%d\n",lastman+1);
  }
  return 0;
}
