#include <stdio.h>
#include <set>
using namespace std;

#define N 50
int state[N][N];

struct stat
{
  int change; //what is the change on toggle
  int who; //what row are we referring to?
  int on; //how many switches are on?
  int off;//how many are off?
  stat(int i, int x,int y):who(i),on(x),off(y){change=off-on;}
  inline bool operator<(const stat& rhs) const
  {
    if(change==rhs.change)
      return who<rhs.who; //if change is same compare based on row
    else
      return change>rhs.change; //else compare based on change value
  }
};
set<stat> S;

void print(int n, int m)
{
  int i,j;
  for(i=0;i<n;++i)
  {
    for(j=0;j<m;++j)
      printf("%d ",state[i][j]);
    printf("\n");
  }
}

void read(int n, int m)
{
  int i,j;
  int cnt[2];
  char buf[N];
  S.clear();
  for(i=0;i<n;++i)
  {
    scanf("%s",buf);
    cnt[0]=0;
    cnt[1]=0;
    for(j=0;j<m;++j)
    {
      state[i][j]=(buf[j]=='*'?1:0);
      cnt[state[i][j]]+=1;
    }
    stat s(i,cnt[1],cnt[0]);
    S.insert(s);
  }
}

int solve(int n, int k)
{
  int i=0;
  set<stat>::iterator left;
  for(i=0;i<k;++i)
  {
    left=S.begin();
    stat s(left->who,left->off,left->on); //maximum is toggled
    S.erase(left);
    S.insert(s); //re-insert after toggle
  }

  int res=0;
  set<stat>::iterator iter;
  for(iter=S.begin();iter!=S.end();++iter)
    res+=iter->on;
  return res;
}

int main()
{
  int n,m,k;
  int num;
  scanf("%d",&num);
  for(int i=0;i<num;++i)
  { 
    scanf("%d %d %d",&n,&m,&k);
    read(n,m);
    printf("%d\n",solve(n,k));
  }
  return 0;
}
