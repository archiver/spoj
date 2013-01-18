#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1000
char a[N], b[N];

int main()
{  
  int end,n,m;
  vector<char> v(N);
  vector<char>::iterator itend,it;
  while(1)
  {
    end=scanf("%s",&a);
    if(end==EOF) break;
    scanf("%s",&b);
    n=strlen(a); m=strlen(b);
    sort(a,a+n);
    sort(b,b+m);
    v.clear();
    itend = set_intersection(a,a+n,b,b+m,v.begin());
    for(it=v.begin();it!=itend;++it)
      printf("%c",*it);
    printf("\n");
  }
  return 0;
}
