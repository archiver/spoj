#include <stdio.h>
#include <string.h>
using namespace std;
#define N 2001
char B[N];

int solve()
{
  int n=strlen(B);
  int cnt=0;
  int flips=0;
  for(int i=0;i<n;++i)
  {
    cnt+=((B[i]=='{')?1:-1);
    if(cnt<0) { cnt=1; flips+=1; }
  }
  return flips+ (cnt/2);
}

int main()
{
   int i=0;
   while(1)
   {
     scanf("%s",&B);
     if(B[0]=='-') break;
     i+=1;
     printf("%d. %d\n",i,solve());
   }
   return 0;
}
