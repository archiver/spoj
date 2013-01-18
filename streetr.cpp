#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 100000
int pos[N];
int diff[N];

int gcd(int a, int b)
{
  if(0==b) return a;
  return gcd(b,a%b);
}

int solve(int n)
{
  int i=0;
  sort(pos,pos+n); //in increasing order

  for(i=0;i<n-1;++i) 
    diff[i]=pos[i+1]-pos[i];
  int mi=diff[0],ma=diff[0];
  
  int d=gcd(diff[0],diff[1]);
  for(i=2;i<n-1;++i) 
    d=d>diff[i]?gcd(d,diff[i]):gcd(diff[i],d);

  int target = (pos[n-1]-pos[0])/d+1;
  return target-n;
}

int main()
{
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;++i)
    scanf("%d",&pos[i]);
  printf("%d\n",solve(n));
  return 0;
}
