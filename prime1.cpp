#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef vector<bool> vbool;
typedef vector<int> vint;

void sieve(int n, vint &primes)
{
    vbool prime(n,true);
    primes.clear();

    int limit=sqrt(n);
    for(int i=2;i<=limit;++i)
	if(prime[i])
	    for(int j=i*i;j<=n;j+=i)
		prime[j]=false;

    for(int i=2;i<=n;++i)
	if(prime[i]) primes.push_back(i);

}

int main()
{
    vint primes;
    sieve(32000, primes);
    int m,n,c,s;
    int i,j,t,cnt;
    bool prime;
    int temp;

    cin>>s;
    c=primes.size();
    for(i=0;i<s;++i)
    {
	cin>>m>>n;
	m=m<2?2:m;
	if(n<=32000)
	{
	    for(j=m;j<=n;++j)
	    {
		temp=sqrt(j);
		for(t=0;t<c && primes[t]<=j;++t)
		{
		    if(j==primes[t]) {printf("%d\n",j);break;}
		}
	    }
	}
	else
	{
	    for(j=m;j<=n;++j)
	    {
		prime=true;
		temp=sqrt(j);
		for(t=0;t<c;++t)
		{
		    if(primes[t]>temp) break; 
		    if(j%primes[t]==0) {prime=false; break;}
		}
		if(prime) printf("%d\n",j);
	    }
	}
	cout<<endl;
    }

    return 0;
}
