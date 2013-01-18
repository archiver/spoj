#include <stdio.h>
#define N 1000000
typedef unsigned long long ull;
ull S[N+1], A[N+1], O[N+1], ans[N+1];

void calc()
{
    int i;
    for(i=1;i<=N;++i)
    {
	S[i]=(S[i-1]+i);
	A[i]=A[i-1]+S[i];
	O[i]=O[i-2]+S[i-1];
	ans[i]=A[i]+O[i];
    } 
}

int main()
{
    int t,i,n;
    calc();
    scanf("%d",&t);
    for(i=0;i<t;++i)
    {
	scanf("%d",&n);
	printf("%lld\n",ans[n]);
    }
    return 0;
}
