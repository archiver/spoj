#include <stdio.h>

#define N 4
char name[N];

int main()
{
  int t,n;
  scanf("%d",&t);
  while(t--)
  {
    int val=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
      scanf("%s",&name);
      if(name[0]=='l') val=val^1;
      else val=val^0;
    }
    if(val)
      printf("lxh\n");
    else
      printf("hhb\n");
  }
  return 0;
}
