#include <stdio.h>

#define N 100000
int O[N];

//int I[N];

bool check(int n)
{
  int i;
  for(i=0;i<n;++i)
    scanf("%d",&O[i]);
  for(i=0;i<n;++i)
  {
    //I[O[i]-1]=i+1;
    if(O[O[i]-1]!=i+1) return false;
  }

  return true;

/*
  for(i=0;i<n;++i)
    if(I[i]!=O[i]) return false;
  return true;
*/
}

int main()
{
  int n;
  while(1)
  {
    scanf("%d",&n);
    if(!n) break;
    if(check(n))
      printf("ambiguous\n");
    else printf("not ambiguous\n");
  }
  return 0;
}
