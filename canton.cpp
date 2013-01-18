#include <stdio.h>

#define N 5000
int d[N];
int r[N];

inline int abs(int x)
{
  return x<0?-x:x;
}

int bisect(int arr[N], int s, int e, int val)
{
  int m = s+(e-s)/2;
  if(arr[m]==val) return m;
  if(s==e)
    return arr[m]>val?m:m+1;
  if(arr[m]>val) return bisect(arr,s,m,val);
  else return bisect(arr,m+1,e,val);
}

void init()
{
  int i=0;
  int diff[N];

  r[0]=1; d[0]=1;
  r[1]=2; d[1]=3;

  diff[0]=7;
  for(i=1;i<N;++i) diff[i]=diff[i-1]+4;
  for(i=1;i<N-2;i+=2) d[i+2]=d[i]+diff[i/2];
  for(i=1;i<N-1;i+=2) d[i+1]=d[i]+1;

  diff[0]=5;
  for(i=1;i<N;++i) diff[i]=diff[i-1]+4;
  for(i=0;i<N-2;i+=2) r[i+2]=r[i]+diff[i/2];
  for(i=0;i<N;i+=2) r[i+1]=r[i]+1;
}

void compute(int n)
{
  int down=bisect(d,0,N-1,n);
  int right=bisect(r,0,N-1,n);

  if(d[down]==n) //present on vertical
     printf("TERM %d IS %d/1\n",n,down+1);
  else if(r[right]==n) //present on horizontal
     printf("TERM %d IS 1/%d\n",n,right+1);
      
  else //present on diagonal
  {
    int row,col;

    if(d[down]>r[right]) //upward
    {
      col = right+1 - (r[right]-n);
      row = down    - (n-d[down-1]);
      printf("TERM %d IS %d/%d\n",n,row,col);
    }
    else //downward
    {
      col = right   - (n-r[right-1]);
      row = down+1  - (d[down]-n);
      printf("TERM %d IS %d/%d\n",n,row,col);
    }
  }
}

int main()
{
  init();
  int t,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    compute(n);
  }
  return 0;
}
