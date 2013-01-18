#include <stdio.h>
#define N 201

char sign[N];
int ones[N];
int diff[N];

int bisect(int s, int e, int val)
{
  int m=(s+e)/2;
  if(ones[m]==val) return m;
  if(s==e)
   return ones[m]>val?m:m+1;
  if(ones[m]>val) return bisect(s,m,val);
  else return bisect(m+1,e,val);
}

int solve(int n)
{
  int i=0,j=0;

  for(i=0;i<n;++i)
  {
    if(sign[i]=='1')
    {
      ones[j]=i;
      j+=1;
    }
  }
  
  if(!j) 
    return 0;

  int s=0, pos=0;
  int len=0,tlen=0;
  int prev,val;
  while(s<j)
  {
    pos=ones[s];
    len=pos;

    diff[pos]=1;
    for(i=pos+1;i<n;++i)
    {
      if(sign[i]=='1')
        diff[i]=diff[i-1]+1;
      else
        diff[i]=diff[i-1]-1;
      if(diff[i]>0) pos=i;
    }
   
    len=(pos-len+1);
    tlen+=len;

    prev=ones[s]-1;
    val=diff[i];
    while(prev>=0 && sign[prev]=='0' && val>0)
    {
      val-=1;
    }
    tlen+=(prev-val+1);
    s=bisect(0,j-1,pos+1);
  }
  return tlen;
}

int main()
{
  int t,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    scanf("%s",&sign);
    printf("%d\n",solve(n));
  }
  return 0;
}
