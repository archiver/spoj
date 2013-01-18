#include <stdio.h>
#include <string.h>

using namespace std;

#define N 1000001
#define M 1000008
int m, k;
int val[N];
int ind[M];
char* s;

void init(int n)
{
  int i=0;
  for(i=0;i<m;++i) ind[i]=-1;

  if(' '==s[0]) val[0]=32%m;
  else if('a'<=s[0] && s[0]<='z') val[0]=(s[0]-'a'+1)%m;
  else val[0]=(s[0]-'A'+51)%m;
  ind[val[0]]=0;

  for(i=1;i<n;++i)
  {
    if(' '==s[i]) val[i]=(val[i-1]+32)%m;
    else if('a'<=s[i] && s[i]<='z') val[i]=(val[i-1]+(s[i]-'a'+1))%m;
    else val[i]=(val[i-1]+(s[i]-'A'+51))%m;
    ind[val[i]]=i;
  }
}

int main()
{
  int t=0;
  int i=0,n=0;
  scanf("%d",&t);
  s=new char[N];
  char c; int ssize=0;
  while(t--)
  {
    getchar();//read \n from previous
    fgets(s,N,stdin);

    n=strlen(s);
    s[n-1]='\0';
    n-=1;
    scanf("%d %d",&m,&k);

    init(n);    
    k=(m+k%m)%m;
    int len=ind[k]+1; //starting at 0
    int tmp, tlen=len;
    int mind=0, mlen=len;
    if(!len) { mind=-1; mlen=-1;}

    for(i=1;i<n;++i)
    {
      tmp=(k+val[i-1])%m;
      if(ind[tmp]==-1) continue;
      tlen=ind[tmp]-i+1;
      if(tlen>mlen)
      {
        mlen=tlen;
	mind=i;
      }
    }
/*
    for(i=0;i<n;++i) printf("%d ",val[i]);
    printf("\n");
    for(i=0;i<m;++i) printf("%d ",ind[i]);
    printf("\n");
    printf("%s %d\n",s,n);
*/
    if(mind==-1)
      printf("-1\n");
    else
      printf("%d %d\n",mind,mlen);
  }
  return 0;
} 
