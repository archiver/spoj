#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

#define N 34
int nums[N];
int n,l,r;
ll cnt=0;

void count(int pos, ll sum)
{
    //check
    if(pos==n)
    {
	if(sum>=l && sum<=r) cnt+=1;
	return;
    }
    
    if(!(sum>r && nums[pos]>0)) 
    {
       count(pos+1,sum);
       count(pos+1,sum+nums[pos]);
    }
}

int main()
{
    int i=0;
    scanf("%d %d %d",&n,&l,&r);
    for(i=0;i<n;++i)
	scanf("%d",&nums[i]);

    sort(nums,nums+n);
    count(0,0);
    printf("%lld\n",cnt);

    return 0;
}
