#include <stdio.h>
#include <set>

using namespace std;
#define SI(n) scanf("%d",&n);
#define N 1000000

typedef multiset<int,greater<int> > si;
int vals[N];

void solve(int n, int k)
{
  int i;
  si s;
  for(i=0;i<k;++i) s.insert(vals[i]);
  for(i=k;i<n;++i)
  {
    printf("%d ",*s.begin());
    s.erase(vals[i-k]);
    s.insert(vals[i]);
  }
  printf("%d\n",*s.begin());
}

int main()
{
  int t,i;
  int n,k;
  SI(n);
  for(i=0;i<n;++i) SI(vals[i]);
  SI(k);
  solve(n,k);
  return 0;
}
