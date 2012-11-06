#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define swap(x,y) {typeof(x) t = (y); y=(x); x=(t);}

typedef pair<int,int> pii;

bool compare(pii x, pii y) { return x.first<y.first; }

int score(int *a, int n)
{
  vector<pii> sorted;
  for(int i=0;i<n;++i) sorted.pb(pii(a[i],i));
  sort(all(sorted),compare);
  
  int sscore=0;
  int small,large;
  if(a[n-1]!=sorted[n-1].first)
  {
    
  }
  for(int i=n-1;i>=0;--i)
  {
    if(a[i]==sorted[n-1].first) continue;

    small=sorted[0].second;
    large=sorted.find
    
    sscore+=sorted[0].first+sorted[i].first;
    swap(a[small],a[large]);
    swap(sorted[0].second,sorted[i].second);
  }
  cout<<sscore<<endl;
  for(int i=0;i<n;++i) cout<<a[i]<<" ";
  cout<<endl;
}  

int main()
{
  int a[]={1,8,9,7,6};
  int n=sizeof(a)/sizeof(int);
  score(a,n);
  return 0;
}
