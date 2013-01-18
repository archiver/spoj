#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 1000000
int arr[N];

bool search(int s, int e, int val)
{
  int m=(s+e)/2;
  if(arr[m]==val) return true;
  if(s==e) return false;
  if(arr[m]>val) return search(s,m,val);
  else return search(m+1,e,val);
}

int main()
{ 
  int n,k;
  int i;
  scanf("%d %d",&n,&k);
  for(i=0;i<n;++i)
    scanf("%d",&arr[i]);
  sort(arr,arr+n);
  int count=0;
  for(i=0;i<n;++i)
    if(search(0,n-1,arr[i]-k)) count+=1;
  printf("%d\n",count);
  return 0;
}

