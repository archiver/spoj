#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

#define N 250
int primes[N];

template <class T>
void print(T *arr, int n)
{
  for(int i=0;i<n;++i) cout<<arr[i]<<" ";
  cout<<endl;
}

void sieve()
{
  bool isprime[N];
  int i=0,j=0;

  int n=sqrt(N)+1;
  for(i=0;i<N;++i) isprime[i]=true;

  for(i=2;i<n;++i)
  {
    if(isprime[i])
    {
      for(j=i*i;j<N;j+=i)
        isprime[j]=false;
    }
  }

  for(i=2,j=0;i<N;++i) 
    if(isprime[i]) { primes[j]=i; ++j;}

  print(&primes[0],j);
}



int main()
{
  sieve();
  return 0;
}
