#include <stdio.h>
#include <set>
using namespace std;
#define N 1000000
typedef unsigned long long ull;
typedef set<ull> si;

ull squares[N+1];
si S;

int bisect_left(int s, int e, ull v)
{
    int m=s+(e-s)/2;
    if(squares[m]==v) return m;
    if(s==e)
    {
	if(squares[m]>v) return m;
	else return m+1;
    }
    if(squares[m]>v) return bisect_left(s,m,v);
    else return bisect_left(m+1,e,v);
}

int possible(ull n)
{
    int pos=bisect_left(0,N,n);
    if(squares[pos]==n) return 1;

    ull residue;
    int tpos,i;

    for(i=pos-1;i>0;--i)
    {
	residue=n-squares[i];
	if(S.find(residue)!=S.end()) return 1;
    }
    return 0;
}

int main()
{
    int i,t;

    for(i=0;i<=N;++i) {squares[i]=i*i;S.insert(squares[i]);}
    
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
