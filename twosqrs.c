#include <stdio.h>
#include <math.h>

#define N 1000000
typedef unsigned long long ull;

ull squares[N+1];

inline int possible(ull n)
{
   ull tsum;
   int i=0,j=sqrt(n);
   while(i<=j)
   {
     tsum=squares[i]+squares[j];
     if(tsum==n) return 1;
     else if(tsum<n) i+=1;
     else j-=1;
   }
   return 0;
}

int main()
{
    ull i;
    for(i=0;i<=N;++i) squares[i]=i*i;

    int t;
    scanf("%d",&t);
    ull n;

    for(i=0;i<t;++i)
    {
	scanf("%lld",&n);
	if(possible(n)) printf("Yes\n");
	else printf("No\n");
    }
    return 0;
}
