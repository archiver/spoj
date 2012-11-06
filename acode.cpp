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

#define number(a,b)  (a-'0')*10+(b-'0')

int decode(string &s)
{
  vi d;
  int num;

  int sz=s.size();
  d.insert(d.begin(),sz,0);

  if(sz==0) return 0;
  if(sz==1) return s[0]!='0'?1:0;

  //sz>=2
  if(s[sz-1]!='0') d[sz-1]=1;

  if(s[sz-2]!='0') 
  {
    d[sz-2]=d[sz-1];
    num=number(s[sz-2],s[sz-1]);
    if(num>=10 && num<=26)  d[sz-2]+=1;
  }

  for(int i=sz-3;i>=0;--i)
  {
    if(s[i]!='0')
    {
      d[i]=d[i+1];
      num=number(s[i],s[i+1]);
      if(num>=10 && num<=26) d[i]+=d[i+2];
    }
  }
  return d[0];
}

int main()
{
  string s;
  while(1)
  {
    cin>>s;
    if(s=="0") break;
    cout<< decode(s) <<endl;
  }
  return 0;
}
