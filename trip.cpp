#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define L 81
#define tr(c,it) for(typeof((c).begin()) it=(c).begin();it!=(c).end(); ++it)

char A[L];
char B[L];
int D[L][L];
int n, m;
set<string> output;

//the dfs technique generally causes tle for some reason!
void backtrack(string &s, int i, int j, int pos, int len)
{
  if(pos==len) { output.insert(s); return; }
  if(i==n || j==m || len-pos!=D[i][j]) return;

  if(A[i]==B[j])
  { 
     s[pos]=A[i]; 
     backtrack(s,i+1,j+1,pos+1,len);
  }
 
  if(D[i][j]==D[i+1][j])
     backtrack(s,i+1,j,pos,len);

  if(D[i][j]==D[i][j+1])
     backtrack(s,i,j+1,pos,len);
}

void lcs()
{
  
  int i,j;
  for(i=0;i<n;++i) D[i][m]=0;
  for(j=0;j<m;++j) D[n][j]=0;

  for(i=n-1;i>=0;--i)
  {
    for(j=m-1;j>=0;--j)
    {
      if(A[i]==B[j]) 
        D[i][j]=1+D[i+1][j+1];
      else
        D[i][j]=max(D[i+1][j],D[i][j+1]);
    }
  } 

  int len=D[0][0];
  string s(len,'\0');

  output.clear();
  backtrack(s,0,0,0,len);
  
  tr(output,it) cout<<*it<<endl;
  cout<<endl;
}

int main()
{
  int T;
  cin>>T;
  for(int i=0;i<T;++i)
  {
    scanf("%s\n",A);
    scanf("%s\n",B);
    n=strlen(A);
    m=strlen(B);
    lcs();
  }
  return 0;
}
