#include <stdio.h>

#define N 10000
int candy[N];

int main()
{ 
  int n;
  int i,sm;
  int res,avg;

  while(1)
  {
    scanf("%d",&n);
    if(-1==n) break;
    sm=0;i=0;
    for(i=0;i<n;++i)
    {
      scanf("%d",&candy[i]);
      sm+=candy[i];
    }
    if(sm%n) {printf("-1\n"); continue;}
    
    avg=sm/n;
    res=0;
    for(i=0;i<n;++i)
      if(candy[i]>avg) res+=(candy[i]-avg);
    printf("%d\n",res);
  }
  return 0;
}
