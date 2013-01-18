#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 50

int A[N];

int solve(int n)
{
   int val=0,s=0;

   for(int i=0;i<n;++i) //clean the array
   {
     if(A[i]>n-1) 
     {
      val+=(A[i]-(n-1));
      A[i]=n-1;
     }
     s+=A[i];
   }
 
   val += abs((n*(n-1))/2 - s);
   return val;
}

int main()
{
  int t,n;
  scanf("%d",&t);
  while(t--)
  {
     scanf("%d",&n);
     for(int i=0;i<n;++i)
       scanf("%d",&A[i]);
     printf("%d\n",solve(n));
  }
  return 0;
}

