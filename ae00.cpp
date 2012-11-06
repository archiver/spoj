#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int rectangles(int n)
{
  set<pii> s;
  for(int i=1;i<=n;++i)
  {
    for(int j=1;i*j<=n;++j)
      s.insert(pii(min(i,j),max(i,j)));
  }
  cout<<s.size()<<endl;
}

int main()
{
  int n;
  cin>>n;
  rectangles(n);
  return 0;
}
