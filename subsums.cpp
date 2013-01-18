#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define N 131075
#define S 18

ll lsum[N];
ll rsum[N];
int lcount[N];
int rcount[N];
ll nums[S<<1];
int position;

int bisect(ll asum[N], int s, int e, ll v)
{
	int m=s+(e-s)/2;
	if(asum[m]==v) return m;
	if(s==e) return asum[m]>v?m:m+1;
	if(asum[m]>v) return bisect(asum,s,m,v);
	else return bisect(asum,m+1,e,v);
}

void subsums(ll numbers[S], int pos, int n, ll s, ll asum[N])
{
	if(pos==n)
	{
		asum[position]=s;
		position+=1;
		return;
	}

	subsums(numbers,pos+1,n,s,asum);
	subsums(numbers,pos+1,n,s+numbers[pos],asum);
}

ll solve(int n, ll l, ll r)
{
	ll lnums[S], rnums[S];

	memset(lnums,0,S*sizeof(int));
	memset(rnums,0,S*sizeof(int));

	sort(nums,nums+n);

	int lsize=n%2?(n+1)/2:n/2;
	int rsize=n%2?(n-1)/2:n/2;

	copy(nums,nums+lsize,lnums);
	copy(nums+lsize,nums+n,rnums);

	position=0;
	subsums(lnums,0,lsize,0,lsum);
	position=0;
	subsums(rnums,0,rsize,0,rsum);

	int l_sum_size = 1<<lsize;
	int r_sum_size = 1<<rsize;

	sort(lsum,lsum+l_sum_size);
	sort(rsum,rsum+r_sum_size);

	int l_pos, r_pos;

	rcount[r_sum_size-1]=0;
	for(int i=r_sum_size-2;i>=0;--i)
	{
	  rcount[i]=0;
	  for(;i>=0 && rsum[i]==rsum[i+1];--i) rcount[i]=1+rcount[i+1];
	}

	lcount[0]=0;
	for(int i=1;i<r_sum_size;++i)
	{
	  lcount[i]=0;
	  for(;i<r_sum_size && rsum[i]==rsum[i-1];++i) lcount[i]=1+lcount[i-1];
	}

	ll res=0;
	for(int i=0;i<l_sum_size;++i)
	{
		l_pos=bisect(rsum,0,r_sum_size-1,l-lsum[i]);
		if(l_pos<r_sum_size && rsum[l_pos]+lsum[i]==l)
		  l_pos=l_pos-lcount[l_pos];

		r_pos=bisect(rsum,0,r_sum_size-1,r-lsum[i]);
		if(r_pos<r_sum_size && rsum[r_pos]+lsum[i]==r)
		  r_pos=r_pos+rcount[r_pos]+1;
		res+=(ll)(r_pos-l_pos);
	}

	return res;
}

int main()
{
	int n;
	ll l,r;
	scanf("%d %lld %lld",&n,&l,&r);
	for(int i=0;i<n;++i)
		scanf("%lld",&nums[i]);
	printf("%lld\n",solve(n,l,r));
	return 0;
}
