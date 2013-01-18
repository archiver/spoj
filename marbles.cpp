#include <stdio.h>
typedef long long ll;

ll solve(int n, int k)
{
  ll i=0, res=1L;
  if(k==1) return n-1;
  for(i=n-1;i>=n-k+1;--i) res*=i;
  printf("%lld\n",res);
  for(i=k-1;i>1;--i) res/=i;
  return res;
}

int main()
{
  int t;
  int n,k;
  scanf("%d",&t);
  while(t--)
  {
     scanf("%d %d",&n,&k);
     if(n<k) printf("0\n");
     else if(n==k) printf("1\n");
     else  printf("%lld\n",solve(n,k));
  }
  return 0;
}
