#include <math.h>
#include <stdio.h>

#define N 500000
#define P 41538

int powers[N][20];

void sieve(int s[P])
{

    int prime[N+1];

    int limit=sqrt(N);
    int i,j;
    for(i=0;i<=N;++i) prime[i]=1;
    for(i=2;i<limit;++i)
    { 
	for(j=i*i;j<=N;j+=i)
	    prime[j]=0;
    }

    for(i=2,j=0;i<=N;++i)
	if(prime[i]) { s[j]=i; ++j;}
}

void populate(int s[P])
{
  int div;
  int i,j;
  int t,res;

  for(i=0;i<P;++i)
  {
    div=s[i];
    res=div;
    t=1;
    while(res<=N)
    {
      powers[div][t]=res;
      res*=div;
      ++t;
    }
    powers[div][t]=res;
  }
}

int bisect_left(int s[P], int l, int r, int n)
{
    if(l>r) return -1;

    int m=l+(r-l)/2;
    if(s[m]==n) return m;
    if(l==r)
    {
	if(s[m]<n) return m+1;
	else return m;
    }
    if(s[m]>n) return bisect_left(s,l,m,n);
    else return bisect_left(s,m+1,r,n);
}

void sumdiv(int num, int s[P])
{
    int ans=1;
    int cnt=0;
    int i=P-1;
    int back=num;
    if(num==1) { printf("1\n"); return;}

    i=bisect_left(s,0,i,num);
    if(s[i]==num) { printf("1\n"); return;}
    i-=1;

    while(i>=0)
    {
	cnt=0;
	int div=s[i];
	while(!(num%div))
	{
	    num/=div;
	    cnt+=1;
	}

	if(cnt==1)
	    ans*=(div+1);
	else if(cnt>1)
	{
	    int res=(powers[div][cnt+1]-1);
	    res=res/(div-1);
	    ans*=res;
	}

	if(s[i]>num)
	{
	    i=bisect_left(s,0,i,num);
	    if(i==-1) break;
	    if(s[i]==num) { ans*=(s[i]+1); break;}

	}
	i-=1;
    }

    printf("%d\n",(ans-back));
}

int main()
{ 
    int s[P];
    sieve(s);
    populate(s);

    int i,t,num;
    scanf("%d",&t);

    for(i=0;i<t;++i)
    {
	scanf("%d",&num);
	sumdiv(num,s);
    }

    return 0;
}
