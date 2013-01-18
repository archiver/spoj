#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator vt;

#define N 5000
int A[N],B[N],C[N],D[N];

int solve(int n)
{
  int i,j,t;
  int sm=0,res=0;
  int left,right;

  vi store(n*n);
  
  for(i=0,t=0;i<n;++i)
    for(j=0;j<n;++j,++t)
      store[t]=A[i]+B[j];

  sort(store.begin(),store.end());
  pair<vt,vt> bounds;
  
  for(i=0;i<n;++i)
  {
    for(j=0;j<n;++j)
    {
      sm=C[i]+D[j];
      bounds=equal_range(store.begin(),store.end(),-sm);
      left=int(bounds.first-store.begin());
      right=int(bounds.second-store.begin());
      
      if(left==right) continue; //includes all non-matching cases
      res+=(right-left);
    }
  }

  return res;
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
  printf("%d\n",solve(n));
  return 0;
}

/*
#include <map>
map<int,int> store;

int solve(int n)
{
  int i,j;
  int sm=0,res=0;

  store.clear();
  for(i=0;i<n;++i)
  {
    for(j=0;j<n;++j)
    {
      sm=A[i]+B[j];
      if(store.find(sm)!=store.end())
        store[sm]+=1;
      else
        store[sm]=1;
    }
  }

  for(i=0;i<n;++i)
  {
    for(j=0;j<n;++j)
    {
      sm=C[i]+D[j];
      if(store.find(-sm)!=store.end())
        res+=store[-sm];
    }
  }
  return res;
}
*/
