#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 201
#define pb push_back

typedef pair<int,int> ii;
typedef vector<ii> vii;

char sign[N];
int diff[N];

int solve(int n)
{
   int i=0,pos=0,ptr=0,start=0,len=0;

   diff[0]=(sign[0]=='1')?1:-1;
   for(i=1;i<n;++i)
      diff[i]=diff[i-1]+((sign[i]=='1')?1:-1);

   while(start<n)
   {
     pos=start;
     for(i=pos+1;i<n;++i)
     {
       if(diff[i]>ptr)
         pos=i;
  }
     ptr=diff[pos];
     if(pos>start || (pos==start && sign[pos]=='1')) len+=(pos-start+1);
     start=pos+1;
   }
   return len;
}

int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      scanf("%s",&sign);
      printf("%d\n",solve(n));
   }
   return 0;
}
