#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

#define N 100001
ull C[N];
ull P[N];

int main()
{
   int n,i;
   while(true)
   {
     scanf("%d",&n);
     if(!n) break;

     for(i=0;i<n;++i) 
       scanf("%llu",&C[i]);

     for(i=0;i<n;++i) 
       scanf("%llu",&P[i]);

     sort(C,C+n);
     sort(P,P+n,greater<int>());

     ull res=0;
     for(i=0;i<n;++i)
       res=res+(C[i]*P[i]);
     printf("%lld\n",res);
   }
   return 0;
}
