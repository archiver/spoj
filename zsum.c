#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

#define PRIME 10000007
#define LIMIT 28

ull powers[LIMIT];
int positions[LIMIT];

int binary(int n)
{
  int cnt=0;
  memset(positions,0,LIMIT*sizeof(int));

  while(n)
  {
    if(n&1)
      positions[cnt]=1;
    n>>=1;
    cnt+=1;
  }

  return cnt;
}

int compute(int n, int limit)
{
  int i=0;
  ull prod=0;

  memset(powers,0,LIMIT*sizeof(ull));

  powers[0]=n%PRIME;
  for(i=1;i<limit;++i)
  {
    prod=powers[i-1]*powers[i-1];
    powers[i]=prod%PRIME;
  }
}

int power(int n, int k)
{
  int cnt=binary(k);
  compute(n,cnt);
  ull res=1;
  int i=0;
  for(i=0;i<LIMIT;++i)
    if(positions[i]) 
      res=(res*powers[i])%PRIME;

  return (int)res%PRIME;
}

int solution(int n, int k)
{
  ull res=0;

  int t1=power(n-1,k);
  t1<<=1;
  int t2=power(n-1,n-1);
  t2<<=1;

  res=power(n,k);
  res=(res+power(n,n))%PRIME;
  res=(res+t1)%PRIME;
  res=(res+t2)%PRIME;

  return (int)(res%PRIME);
}

int main()
{
  int n,k;
  while(1)
  {
    scanf("%d %d",&n,&k);
    if(!n && !k) break;
    printf("%d\n",solution(n,k));
  }
  return 0;
}
