#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;
char s[21];
main()
{
  int t=10,n,cnt;
  ull res;
  while(t--)
  {
    scanf("%s",s);
    n=strlen(s);
    cnt=0;res=1LL;
    for(int i=0;i<n;++i)
    {
      if(s[i]=='T' || s[i]=='D' || s[i]=='L' || s[i]=='F')
        ++cnt;
    }
    printf("%llu\n",res<<cnt);
  }
}
