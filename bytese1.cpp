#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

bool **vis=NULL;
bool *mvis=NULL;
int **arr=NULL;
int *marr=NULL;
int n,m;

void allocate()
{
   //free memory
   if(marr) free(marr);
   if(arr) free(arr);
   if(mvis) free(mvis);
   if(vis) free(vis);

   marr=new int[n*m];
   arr=new int*[n];

   arr[0]=marr;
   for(int i=1;i<n;++i) arr[i]=arr[i-1]+m;
   
   mvis=new bool[n*m];
   vis=new bool*[n];
   vis[0]=mvis;
   for(int i=1;i<n;++i) vis[i]=vis[i-1]+m;

   for(int i=0;i<n;++i)
   {
     for(int j=0;j<m;++j)
       cin>>arr[i][j];
   }
}

void print()
{
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
       cout<<arr[i][j]<<" ";
    cout<<endl;
  }
}

int paths(int i, int j, int di, int dj, int l)
{

  if(l<=0) return INT_MIN; //timedout
  if(i<0 || j<0 || i>=n || j>=m) return INT_MIN; //hit boundary
  if(vis[i][j]) return INT_MIN; //already visited
  if(di==i && dj==j) 
  {    
     int res=l-arr[i][j];
     return res>=0?res:INT_MIN;
  }

 
  vis[i][j]=true;

  int left=paths(i-1,j,di,dj,l-arr[i][j]);
  int right=paths(i+1,j,di,dj,l-arr[i][j]);
  int top=paths(i,j-1,di,dj,l-arr[i][j]);
  int bottom=paths(i,j+1,di,dj,l-arr[i][j]);
  
  vis[i][j]=false;

  int buf=max(left,right);
  buf=max(buf,max(top,bottom));
  return buf; 
}

void solve(int di, int dj, int T)
{
  int res=paths(0,0,di-1,dj-1,T);
  //printf("%d %d %d\n",di,dj,T);
  if(res==INT_MIN)
  {
    cout<<"NO"<<endl;
  }
  else
  {
    cout<<"YES"<<endl;
    cout<<res<<endl;
  }
}

int main()
{
  int cases;
  int di,dj,T;

  cin>>cases;
  for(int i=0;i<cases;++i)
  {
    cin>>n>>m;
    allocate();
    cin>>di>>dj>>T;
    solve(di,dj,T);
  }
  return 0;
}
