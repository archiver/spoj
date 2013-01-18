#include <stdio.h>
#include <set>

using namespace std;

typedef multiset<int> si;

si g;
si m;

bool solve()
{
  int mg,mm;
  while(!g.empty() && !m.empty())
  {
    mg=*g.begin();
    mm=*m.begin();
    if(mg<mm) 
      g.erase(g.begin());
    else 
      m.erase(m.begin());
  }

  return m.empty();
}

int main()
{
  int t;
  int ng,nm;
  int i,temp;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&ng,&nm);
    g.clear(); m.clear();
    for(i=0;i<ng;++i) 
    {
      scanf("%d",&temp);
      g.insert(temp);
    }
    for(i=0;i<nm;++i) 
    {
      scanf("%d",&temp);
      m.insert(temp);
    }

    if(solve()) printf("Godzilla\n");
    else printf("MechaGodzilla\n");
  }
  return 0;
}
