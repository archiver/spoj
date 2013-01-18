#include <stdio.h> 
#define SI(n) scanf("%d",&n)
#define N 10000

int top[N];
int down[N];

int tpoints[N];
int dpoints[N];
int ttotal[N+2];
int dtotal[N+2];

inline int max(int a, int b)
{
  return a>b?a:b;
}

int solve(int n, int m)
{
  int i=0,j=0;
  int mpoint=1;
  tpoints[0]=-1;
  dpoints[0]=-1;

  while(i<n && j<m)
  {
    if(top[i]==down[j])
    {
      tpoints[mpoint]=i;
      dpoints[mpoint]=j;
      mpoint+=1;
      i+=1; j+=1;
    }

    else if(top[i]>down[j]) j+=1;
    else i+=1;
  }
  tpoints[mpoint]=n;
  dpoints[mpoint]=m;
  
  for(i=0;i<mpoint;++i)
  {
    ttotal[i]=0; 
    dtotal[i]=0;

    for(j=tpoints[i]+1;j<tpoints[i+1];++j) 
      ttotal[i]+=top[j];
    for(j=dpoints[i]+1;j<dpoints[i+1];++j) 
      dtotal[i]+=down[j];
  }

  int res=0;
  for(i=0;i<mpoint;++i)
    res+=max(ttotal[i],dtotal[i]);

  for(i=1;i<mpoint;++i)
    res+=top[tpoints[i]];

  return res;
}

int main()
{
  int n,m,i;
  while(1)
  {
    SI(n);
    if(!n) break;
    for(i=0;i<n;++i) SI(top[i]);
    SI(m);
    for(i=0;i<m;++i) SI(down[i]);
    printf("%d\n",solve(n,m));
  }
  return 0;  
}

