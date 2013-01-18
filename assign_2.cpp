#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define N 20
#define pb push_back

bool prefs[N][N];
bool visited[N];
vvi  pdict(N,vi(N,0));
ull cnt=0;
int n=0;

void precompute(int cur[N])
{
  int i,j;
  for(i=0;i<n;++i)
  {
    pdict[i].clear();
    for(j=0;j<n;++j)
      if(prefs[j]) pdict[i].pb(j);
  }
  memset(cur,0,sizeof(int)*N); //reset cur
  memset(cur,0,sizeof(bool)*N); //reset visited
}

void traverse(int pos,int cur[N])
{
   if(pos==n)
   {
     cnt+=1;
     return;
   }

   for(int i=0;i<pdict[pos].size();++i)
   {
     int job=pdict[pos][i];
     cur[pos]=job;
     if(visited[job]) continue;
     visited[job]=true;
     traverse(pos+1,cur);
     visited[job]=false;
   }
}

int main()
{
  int i,j;
  int cur[N];

  n=10;
  for(i=0;i<n;++i)
    for(j=0;j<n;++j)
      prefs[i][j]=1;

  precompute(cur);
  traverse(0,cur);

  cout<<cnt<<endl;
  return 0;
}
