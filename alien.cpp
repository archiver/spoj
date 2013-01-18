#include <stdio.h>
#include <limits.h>

#define A 100000
int B[A];
int sum[A];

int bisect(int s, int e, int val)
{
  int m=(s+e)/2;
  if(sum[m]==val) return m+1;
  if(s==e)
    return sum[m]>val?m:m+1;
  if(sum[m]>val) return bisect(s,m,val);
  else return bisect(m+1,e,val);
}

void solve(int a, int b)
{
  sum[0]=B[0];
  int mlen=-1,mval=INT_MAX,len=0,val=b;
  int i,pos=0,ppos=0;
  
  for(i=1;i<a;++i)
    sum[i]=sum[i-1]+B[i];
  
  pos=bisect(ppos,a-1,val);
  if(pos)
  {
    len=pos;
    val=sum[pos-1];
    mlen=len;
    mval=val;
  }

  for(i=1;i<a;++i)
  {
    val=b+sum[i-1];
    ppos=pos;
    pos=bisect(ppos-1,a-1,val);
    if(ppos==pos+1) continue;

    len=pos-i;

    val=sum[pos-1]-sum[i-1];
    if(len==mlen)
    {
      if(mval>val)
        mval=val;
    }
    else if(len>mlen)
    {
       mlen=len;
       mval=val;
    }
  }
  printf("%d %d\n",mval,mlen);
}

int main()
{
  int t,a,b,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&a,&b);
    for(i=0;i<a;++i)
      scanf("%d",&B[i]);
    solve(a,b);
  } 
  return 0;
}
