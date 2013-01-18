#include <stdio.h>
#include <set>
using namespace std;
typedef pair<int,int> ii;
typedef unsigned int uint;

#define tr(a,it) for(typeof((a).begin()) it=(a).begin();it!=(a).end();++it)

inline int abs(int x)
{
  return x<0?-x:x;
}

int gcd(int a, int b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}

ii normalize(int a, int b)
{
  int r = (a>b) ? gcd(a,b): gcd(b,a);
  return ii(a/r,b/r);
}

int solve(int x, int y)
{
  int ax=abs(x);
  int ay=abs(y);

  int a=abs(x-y);
  int den=ax<ay?ax:ay;
  int num=(ax+ay)-den;
  long long sign = (1L)<<32;
  if((x & (sign))^(y & (sign))) num=-num;

  int pnum;
  int i,j;
  set<ii> s;
  s.insert(ii(0,1));

  for(i=0;i<den;++i)
  {
     pnum=(2*num*i)%den;
     for(j=0;j<a;++j)
       if((2*j*den-pnum)>0)
         s.insert(normalize(2*j*den-pnum,a*den));
  }
  tr(s,it) printf("%d/%d pi\n",it->first,it->second);
  return s.size();
}

int main()
{
  int t;
  int a,b;
  scanf("%d\n",&t);
  while(t--)
  {
    scanf("%d %d",&a,&b);
    printf("%d\n",solve(a,b));
  }
}
