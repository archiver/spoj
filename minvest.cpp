#include <stdio.h>
#include <algorithm>

#define M 50000
#define D 10
using namespace std;

typedef pair<int,int> ii;

ii B[D];
int V[M];

int solve_year(int value, int d)
{
  int start=value/1000, end=value;
  int i,j;

  for(j=0;j<=start;++j) V[j]=0; //initialize to 0

  for(i=0;i<d;++i)
    for(j=B[i].first;j<=start;++j)
      V[j]=std::max(V[j],V[j-B[i].first]+B[i].second);

  int interest=0;
  for(j=0;j<=start;++j) //find the maximum value among all possible
    if(V[j]>interest)
      interest=V[j];

  return end+interest;
}

int solve(int initial, int d, int y)
{
  int value=initial;
  for(int i=0;i<y;++i)
    value=solve_year(value,d);
  return value;
}

int main()
{ 
  int value,years;
  int t,d,bval,bint;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&value,&years);
    scanf("%d",&d);
    for(int i=0;i<d;++i)
    {
     scanf("%d %d",&bval,&bint);
     bval/=1000;
     B[i]=ii(bval,bint);
    }
    sort(B,B+d);
    printf("%d\n",solve(value,d,years));
  }
  return 0;
}
