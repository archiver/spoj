#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;
#define pb push_back

bool nPermute(vi &s, int n)
{
  int k=-1,l=-1;
  int i,j;

  for(i=0;i<n-1;++i)
    if(s[i+1]>s[i]) k=i;

  if(k==-1) return false;

  for(i=k+1;i<n;++i)
    if(s[i]>s[k]) l=i;

  swap(s[l],s[k]);
  reverse(s.begin()+k+1,s.end());
  return true;
}

int main()
{
  vi t;
  for(int i=0;i<15;++i) t.pb(i);

  int n=t.size();
  ull cnt=0;
  do
  {
    //for(int i=0;i<n;++i) cout<<t[i]<<" ";
    //cout<<endl;
    cnt+=1;
  }while(nPermute(t,n));
  cout<<cnt<<endl;

  return 0;
}

