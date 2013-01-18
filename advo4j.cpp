#include <iostream>
using namespace std;
#define N 1000000

int vals[N+2];

void populate()
{
    vals[2]=3;
    int t=4;
    for(int i=3;i<=N;i+=2)
    {
      vals[i]=t;
      vals[i+1]=vals[i];
      t+=1;
    }
}

int main()
{   
    populate();
    int t,n;
    cin>>t;
    for(int i=0;i<t;++i)
    {
      cin>>n;
      if(n==3) cout<<3<<endl;
      int b=n%2?(n+1)/2:n/2;
      cout<<vals[b]<<endl;
    }
    return 0;
}
