#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;

//#define DEBUG
#define N 20001

char colors[N];
int fcnt[N];
int bcnt[N];
int gcount=0;

template <class T>
void print(int n, T arr[N])
{
  for(int i=0;i<n;++i) cout<<arr[i]<<" ";
  cout<<endl;
}

void read(int n)
{
  scanf("%s",colors);
  memset(fcnt,0,n*sizeof(int));
  memset(bcnt,0,n*sizeof(int));
  for(int i=n-2;i>=0;--i)
    if(colors[i]==colors[i+1]) fcnt[i]=fcnt[i+1]+1;

  for(int i=1;i<n;++i)
    if(colors[i]==colors[i-1]) bcnt[i]=bcnt[i-1]+1;
}

inline int MIN(int a, int b)
{
  return a<b?a:b;
}

bool solveit(int pos, char cur[N], int n, int k)
{
  if(pos>=n) return true;

  int fwd=pos+fcnt[pos];
  int rev=pos-bcnt[pos];

  if(fwd-rev+1>=k)
  {
    int max_front=MIN(1+fwd,pos+k);
    for(int i=pos;i<max_front;++i)
      cur[i]=colors[pos];
    gcount+=1;
  }
  else
  {
     for(
  }

  return solveit(max_front,cur,n,k);
}

int solve(int n, int k)
{
  char cur[N];
  memset(cur,'\0',sizeof(char)*N);
  gcount=0;
  
  for(int i=0;i<k;++i) cur[i]=colors[0];
  int pos=MIN(1+fcnt[0],k);
  
  bool ans = solveit(pos,cur,n,k);
#ifdef DEBUG 
  print(n,cur);
#endif  
  if(ans)
     return 1+gcount;
  else return -1;
}

int main()
{
  int t;
  scanf("%d",&t);
  int n,k;
  for(int i=0;i<t;++i)
  {
    scanf("%d %d",&n,&k);
    read(n);
#ifdef DEBUG    
    print(n,colors);
    print(n,fcnt);
    print(n,bcnt);
#endif   
    printf("%d\n",solve(n,k));
  }
  return 0;
}
