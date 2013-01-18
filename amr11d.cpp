#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi score;

int solve(int n)
{
  //sanitize
  int sum=0, diff=0;
  int target = ((n)*(n-1))/2;
  int i,residue=0;
  int low,cnt,lowest;
  vi::iterator it;
  for(i=0;i<n;++i)
  {
    if(score[i]>(n-1))
    {
      diff+=(score[i]-n+1);
      score[i]=n-1;
    }
    sum+=score[i];
  }

  if(sum>target)
  {
    while(sum>target)
    {
      sort(score.begin(),score.end());
      residue=(sum-target);
      low = upper_bound(score.begin(),score.end(),0)-score.begin();
      lowest=score[low];
      if(residue<lowest)
      {
        score[low]-=residue;
	sum-=residue;
	diff+=residue;
      }
      else
      {
        cnt=residue/lowest;
        for(i=low;i<n && cnt>0;++i,--cnt)
        {
	  score[i]-=lowest;
	  diff+=lowest;
          sum-=lowest;
        }
      }
    }
  }
   
  else if(sum<target)
  {
    while(sum<target)
    {
      sort(score.begin(),score.end());
    }
  }

  return diff;
}

int main()
{
  int t,n,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    score.resize(n);
    for(i=0;i<n;++i) scanf("%d",&score[i]);
    printf("%d\n",solve(n));
  }
  return 0;
}
