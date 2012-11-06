#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()

bool compare(pii a, pii b) { return a.first<b.first; }

//balanced binary tree as binary search on sorted array
int btree(vector<pii>& ints, int s, int e, int &sm)
{
   if(s>e) return INT_MIN;
   if(s==e) { sm+=ints[s].second; return ints[s].second; }
   
   int m=s+(e-s)/2;
   int lsum=0,rsum=0;

   int left = btree(ints,s,m-1,lsum);
   int cur = ints[m].second+lsum;
   int right = btree(ints,m+1,e,rsum)+cur;
   int mval=max(left,max(cur,right));
  
   sm+=(lsum+ints[m].second+rsum);
   return mval;
}

void solve(vector<pii> &ints)
{
  
  int n=sz(ints);
  int sm=0;
  cout<< btree(ints,0,n-1,sm) <<endl;
}

int main()
{
  int cases,lines;
  cin>>cases;
  pii t;
  vector<pii> ints;
  for(int i=0;i<cases;++i)
  {
    cin>>lines;
    ints.clear();
    for(int j=0;j<lines;++j)
    {
      cin>>t.first;
      t.second=1;
      ints.pb(t);
      cin>>t.first;
      t.second=-1;
      ints.pb(t);
    }
    sort(all(ints),compare);
    solve(ints);
  }
  return 0;
}
