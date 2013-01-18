#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  int x,y;
  for(int i=0;i<t;++i)
  {
    cin>>x>>y;
    if(x==y) //top right
    {
      int g=y/2;
      cout<<(g*4+y%2)<<endl;
    }
    else if(x==y+2)
    {
      int g=y/2;
      cout<<(g*4+2+y%2)<<endl;
    }
    else
      cout<<"No Number"<<endl;
  }

  return 0;
}
