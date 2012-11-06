#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define tr(c,it) for(typeof((c)) it=(c).begin();it!=(c).end();it++)
#define all(c) (c).begin(),(c).end()
int main()
{
  string s("aaabbabaa");
  vector<char> vc;
  vc=copy(all(s));
  set<string> sstring;
  tr(vc,it)
  {
    cout<<*it<<endl;
  }
  return 0;
}
