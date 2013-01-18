#include <stdio.h>

#define N 1000
int list[N];
int sums[2][N];

inline int abs(int n)
{
  return n<0?-n:n;
}

int solve(int n)
{
  int i;
  
  sums[0][0]=list[0];
  sums[1][1]=list[1];

  for(i=2;i<n;i+=2)
    sums[0][i]=sums[0][i-2]+list[i];

  for(i=3;i<n;i+=2)
    sums[1][i]=sums[1][i-2]+list[i];
  
  int start=0,end=n-1;
  while(start<end)
  {
    if(start&1) //start is odd, end is even
    {
      even = sums[0][end]-sums[0][start+1]+list[start+1];
      odd = sums[1][end-1]-sums[1][start]+list[start];
      if(even>=odd)
      {  
        
      }
    }
    else //start is even, end is odd
    {
      even = sums[0][end-1]-sums[0][start]+list[start];
      odd = sums[1][end]-sums[1][start+1]+list[start+1];
    }
  }
  return 0;
}

int main()
{
  int n,i;
  int cnt=0;
  while(true)
  {
    scanf("%d",&n);
    if(!n) break;
    for(i=0;i<n;++i)
      scanf("%d",&list[i]);
    cnt+=1;
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",cnt,solve(n));
  }
  return 0;
}
