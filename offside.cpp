#include <stdio.h>
#include <algorithm>
using namespace std;
#define P 11
int A[P];
int D[P];

void solve(int a, int d)
{
  int i;
  int att=A[0];
  for(i=1;i<a;++i) 
    if(A[i]<att) att=A[i];

  sort(D,D+d);
  if(att<D[1]) 
    printf("Y\n");
  else
    printf("N\n");

}

int main()
{
  int a,d;
  int i;
  while(1)
  {
    scanf("%d %d",&a,&d);
    if(!a && !d) break;
    for(i=0;i<a;++i) scanf("%d",&A[i]);
    for(i=0;i<d;++i) scanf("%d",&D[i]);
    solve(a,d);
  }
  return 0;
}
