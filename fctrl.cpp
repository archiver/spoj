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

int zeros(int n)
{
  int total=0;
  while(n)
  {
    n=n/5;
    total+=n;
  }
  return total;
}



int main()
{
  int cases;
  int input;
  cin>>cases;
  for(int i=0;i<cases;++i)
  {
     cin>>input;
     cout<<zeros(input)<<endl;
  }
  return 0;
}
