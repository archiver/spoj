#include <stdio.h>
#define N 1000000

typedef unsigned long long ull;

ull squares[N+1];

int bisect(int s, int e, ull v)
{
    int m=s+(e-s)/2;
    if(squares[m]==v) return m;
    if(s==e)
    {
	if(squares[m]>v) return m;
	else return m+1;
    }
    if(squares[m]>v) return bisect(s,m,v);
    else return bisect(m+1,e,v);
}

int search(int s, int e, ull v)
{
    int m=s+(e-s)/2;
    if(squares[m]==v) return 1; //found
    if(s==e) return 0; //not found
    if(squares[m]>v) return search(s,m,v);
    else return search(m+1,e,v);
}

int twosum(int e, ull v)
{
   ull tsum;
   int i=0,j=e;
   while(i<=j)
   {
     tsum=squares[i]+squares[j];
     if(tsum==v) return 1;
     else if(tsum<v) i+=1;
     else j-=1;
   }

   return 0;
}

int possible(ull n)
{
    int pos=bisect(0,N,n);
    return twosum(pos,n);
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
