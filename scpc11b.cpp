#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

#define DEST 1422
#define STAT 200

bool possible(vi &s)
{
  int total=STAT;
  for(int i=1;i<s.size();++i)
  {
    total-=(s[i]-s[i-1]);
    if(total<0) return false;
    total+=STAT;
  }

  total-=(DEST-s[s.size()-1]);
  if(total<0) return false;

  total-=(DEST-s[s.size()-1]);
  if(total<0) return false;

  for(int i=s.size()-1;i>0;--i)
  {
    total+=STAT;
    total-=(s[i]-s[i-1]);
    if(total<0) return false;
  }

  return true;
}

int main()
{
  int n;
  vi s;
  while(1)
  {
    cin>>n;
    if(!n) break;

    s.resize(n);
    for(int i=0;i<n;++i) cin>>s[i];
    sort(s.begin(),s.end());
    if(possible(s)) cout<<"POSSIBLE\n";
    else cout<<"IMPOSSIBLE\n";
  }
  cout<<endl;
  return 0;
}
