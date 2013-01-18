#include <iostream>
#include <string.h>
using namespace std;

#define N 13
#define K 99

int D[N][K];

void calculate()
{
  int i,k,t;
  int border=0,pborder=0;
  memset(D[0],K,0);
  memset(D[1],K,0);
  D[1][0]=1;

  for(i=2;i<N;++i)
  {
    memset(D[i],K,0);
    border = (i*(i-1))/2;
    pborder=((i-1)*(i-2))/2;

    D[i][0]=1; //ascending order
    D[i][border]=1; //descending order
    
    for(k=1;k<=pborder;++k)
      for(t=0;t<=k;++t) D[i][k]+=D[i-1][t];
    
    for(;k<border;++k)
      for(t=k-(i-1);t<=pborder;++t) D[i][k]+=D[i-1][t];
  }
}

int main()
{
  calculate();
  int d;
  int n,k;
  cin>>d;
  for(int i=0;i<d;++i)
  {
    cin>>n>>k;
    cout<<D[n][k]<<endl;
  }
  return 0;
}
