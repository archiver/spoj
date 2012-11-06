#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int arr[10];
int seq[10];
int n;

int lis()
{
  int len=0, mlen=0;
  for(int i=0;i<n;++i)
  {
    len=0;
    for(int j=0;j<i;++j)
      if(arr[i]>arr[j] && seq[j]>len) len=seq[j];
    seq[i]=len+1;
  }

  for(int i=0;i<n;++i)
    if(seq[i]>mlen) mlen=seq[i];
  return mlen;
}

int main()
{
  cin>>n;
  for(int i=0;i<n;++i) cin>>arr[i];
  cout<< lis() <<endl;
}
