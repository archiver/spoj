#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

#define PRIME 1000000007

int fibsum(int m, int n)
{
    ull work[3];
    ull res;
    work[0]=0;
    work[1]=1;

    if(m>1)
    {
        res=0;
	for(int i=2;i<m;++i)
	    work[i%3]=(work[(3+i-1)%3]+work[(3+i-2)%3])%PRIME;

	for(int i=m;i<=n;++i)
	{
	    work[i%3]=(work[(3+i-1)%3]+work[(3+i-2)%3])%PRIME;
	    res=(res+work[i%3])%PRIME;
	}
    }
    else
    {
	if(!n) return 0;
	res=1;
	for(int i=2;i<=n;++i)
	{
	    work[i%3]=(work[(3+i-1)%3]+work[(3+i-2)%3])%PRIME;
	    res=(res+work[i%3])%PRIME;
	}
    }
    return (int)(res%PRIME);
}

int fibsum_2(int m, int n)
{
  const double inverseSqrt5 = 0.44721359549995793928183473374626;
  const double phi = 1.6180339887498948482045868343656;
  return 0;
}

int main()
{
    int m,n;
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
      cin>>m>>n;
      cout<<fibsum(m,n)<<endl;
    }
    return 0;
}
