#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  int x,y,z;

  while(1)
  {
    cin>>x>>y>>z;
    if(!x && !y && !z) break;
    else if(!x || !y || !z) 
      printf("AP %d\n",z+(y-x));
    else
    {
      if(x+z==(y<<1))
        printf("AP %d\n",z+(y-x));
      else
        printf("GP %d\n",z*(y/x));
    }
  }
  return 0;
}
