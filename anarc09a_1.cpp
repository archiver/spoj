#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define LEN 2000
#define INF 4000

int work[LEN+1][LEN+1];

inline int MIN(int a, int b)
{
  return a<=b?a:b;
}

bool isbalanced(string &s)
{
  int t=0;
  for(int i=0;i<s.size();++i)
  {
    if(s[i]=='{') t+=1;
    else t-=1;
    if(t<0) return false;
  }
  return t==0;
}

int convert(string s)
{
  for(int i=0;i<LEN;++i) memset(work[i],0,LEN*sizeof(int));

  int n=s.size();
  if(n%2) return INF;
  if(isbalanced(s)) return 0;

  return 0;

}

int T(string s)
{
    int n=s.size();

    //base cases
    if(n%2==1) return INF;
    if(!n || s=="{}") return 0;
    if(s=="{{" || s=="}}") return 1;
    if(s=="}{") return 2;
    
    if(isbalanced(s)) return 0;

    string temp;
    temp.push_back(s[0]);
    temp.push_back(s[n-1]);
    int res=T(temp)+T(s.substr(1,n-2));

    for(int i=2;i<n;i+=2)
	res=MIN(T(s.substr(0,i))+T(s.substr(i,n-i)), res);
    return res;
}

int main()
{   
  string s="}}}}}}}}}}}}}}}}{{{{{{{{{{";
  //cout<<T(s)<<endl;
  return 0;
}
