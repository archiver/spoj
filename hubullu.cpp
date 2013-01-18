#include <stdio.h>

int main()
{
  int t,n,w;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&w);
    if(w==0)
      printf("Airborne wins.\n");
    else
      printf("Pagfloyd wins.\n");
  }
  return 0;
}
