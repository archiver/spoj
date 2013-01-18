#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
#define N 100001
char L[N], R[N];

int main()
{
  string a,b;
  int n,m,i,j;
  while(1)
  {
    scanf("%s",&L);
    scanf("%s",&R);
    if(L[0]=='*' && R[0]=='*') break;
    n=strlen(L); m=strlen(R);
    a.clear(); b.clear();
    for(i=0;i<n && L[i]=='0';++i);
    if(i==n) a="0";
    else
    {
      a.resize(n-i);
      copy(L+i,L+n,a.begin());
    }
    for(j=0;j<m && R[j]=='0';++j);
    if(j==m) b="0";
    else
    {
      b.resize(m-j);
      copy(R+j,R+m,b.begin());
    }
    if(a.size()<b.size())
      printf("<\n");
    else if(a.size()>b.size())
      printf(">\n");
    else
    {
      if(a>b) printf(">\n");
      else if(a<b) printf("<\n");
      else printf("=\n");
    }
  }  
  return 0;
}
