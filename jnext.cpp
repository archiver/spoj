#include <stdio.h>
#define N 1000001
char inp[N];

void next_permute(int n)
{
  int k=-1,l,i,j;
  for(i=0;i<n-1;++i)
    if(inp[i]<inp[i+1]) k=i;
    
  if(k==-1) {
    inp[0]='-';
    inp[1]='1';
    inp[2]='\0';
    return;
  }
  for(i=k+1;i<n;++i)
    if(inp[i]>inp[k]) l=i;

  char t = inp[k];
  inp[k]=inp[l];
  inp[l]=t;

  i=k+1,j=n-1;
  while(i<j)
  {
    t=inp[i];
    inp[i]=inp[j];
    inp[j]=t;
    i+=1;j-=1;
  }
  inp[n]='\0';
}

int main()
{
  int t,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
      scanf("%d",&inp[i]);
      inp[i]+='0';
    }
    next_permute(n);
    printf("%s\n",inp);
  }
  return 0;
}
