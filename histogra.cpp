//note that while working with statically typed languages it is very important to look at the bounds to choose the data type to be used. the first instance where i encountered this is here!!

#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef pair<int,long long> pii;

#define sz(c) (c).size()

long long maxarea(vi& hist)
{
  int start,pos, height;
  long long area=0;
  stack<pii> s;
  pii t;
  for(pos=0;pos<sz(hist);++pos)
  {
    start=pos;
    height=hist[pos];
    while(1)
    {
      if(s.empty() || height>s.top().second)
        s.push(pii(start,height));
      
      else if(!s.empty() && height<s.top().second)
      {
        t=s.top();
	area=max(area,t.second*(pos-t.first));
        start=t.first;
	s.pop();
        continue;
      }
      break;
    }
  }

  while(!s.empty())
  {
    t=s.top();
    s.pop();
    area=max(area,t.second*(pos-t.first));
  }
  return area;
}

int main()
{
  vi hist; 
  int i,n;
  while(1)
  {
    cin>>n;
    if(!n) break;
    hist.resize(n);
    for(i=0;i<n;++i) cin>>hist[i];
    cout<< maxarea(hist) <<endl;
  }
  return 0;
}

