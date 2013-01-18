#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  set<int> mine;
  set<int> others;

  int nm, no;
  int temp;

  scanf("%d",&nm);
  for(int i=0;i<nm;++i)
  {
    scanf("%d",&temp);
    mine.insert(temp);

    scanf("%d",&no);
    for(int j=0;j<no;++j)
    {
      scanf("%d",&temp);
      others.insert(temp);
    }
  }
  

  vector<int> res(others.size());
  vector<int>::iterator it;

  it=set_intersection(mine.begin(),mine.end(),others.begin(),others.end(),res.begin());

  printf("%d\n",others.size()-int(it-res.begin()));

  return 0;
}

