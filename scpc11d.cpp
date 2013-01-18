#include <stdio.h>
#include <algorithm>
using namespace std;
int sides[3];

bool solve()
{
  bool pyth = (sides[2]*sides[2] == sides[0]*sides[0] + sides[1]*sides[1]);
  bool ineq = false;
  ineq|= (sides[1]+sides[2]>sides[3]);
  ineq|= (sides[2]+sides[3]>sides[1]);
  ineq|= (sides[3]+sides[1]>sides[2]);
  
  return pyth && ineq;
}

int main()
{
  while(1)
  {
    scanf("%d %d %d",&sides[0],&sides[1],&sides[2]);
    if(!sides[0] && !sides[1] && !sides[2]) break;
    sort(sides,sides+3);
    if(solve())
      printf("right\n");
    else printf("wrong\n");
  }
  return 0;
}
