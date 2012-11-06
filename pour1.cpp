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
#define proper(a,b) max(a,b),min(a,b)

int gcd(int a, int b)
{
  if(b==0) return a;
  if(b==1) return 1;
  return gcd(b,a%b);
}

int normalize(int &a, int &b, int &c)
{
  //removes the least power of 2 from all of them
  int g=gcd(proper(a,b));
  g=gcd(proper(g,c));
  a=a/g;
  b=b/g;
  c=c/g;
}

int calc(int f, int s, int t)
{
//f=first, s=second, t=target
  int x=min(a,b);
  int y=max(a,b);
  if(t<x)
    return 1+calc(x,y,y-(x-t));
  else return 2+calc(x,y,y-t);
}

int pour(int a, int b, int c)
{
  if((c>a && c>b) || c<0) return -1;
  if(c==0 || c==a || c==b) return 1;
  if(a%2==0 && b%2==0)
  {
    normalize(a,b,c);
    if(a%2==0 && b%2==0 && c%2!=0) return -1;
  }
  return calc(a,b,c);
}

int main()
{
  return 0;
}
