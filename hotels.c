#include <stdio.h>
#define N 300000
int val[N];
typedef unsigned long long ull;

void solve(int n, int m)
{
  ull res=0;
  int start=0,end=0;
  int mval=0;
  do
  {
    while(end<n && res<m)
    {
      res+=val[end];
      if(res<m && res>mval) mval=res;
      end+=1;
    }
    while(start<end && res>m)
    {
      res-=val[start];
      if(res<m && res>mval) mval=res;
      start+=1;
    }
    if(res==m)
    { 
      printf("%d\n",m);
      return;
    }
  }while(end<n && end>start);

  printf("%d\n",(int)mval);
}

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  int i;
  for(i=0;i<n;++i) scanf("%d",&val[i]);
  solve(n,m);
  return 0;
}
