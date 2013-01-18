#include <stdio.h>
#include <algorithm>
using namespace std;

int costs[][2]={{+3,+2},
               {-5,-10},
	       {-20,+5}};

int solve(int h, int a, int s)
{
  if(h<=0 || a<=0) return 0;

  int hnew=h+costs[s][0];
  int anew=a+costs[s][1];

  int first = 1+solve(hnew,anew,(s+1)%3);
  int second = 1+solve(hnew,anew,(s+2)%3);
  return max(first,second);
}

int solveUtil(int H, int A)
{
  int air=solve(H,A,0);
  int water=solve(H,A,1);
  int fire=solve(H,A,2);

  int res=max(air,water);
  res=max(res,fire);
  return res-1;
}

int main()
{
  int t,h,a;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&h,&a);
    printf("%d\n",solveUtil(h,a));
  }
  return 0;
}
