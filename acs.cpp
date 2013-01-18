#include <stdio.h>

#define N 5
int row[N],rrow[N];

void init()
{
  int i;
  for(i=0;i<N;++i)
  {
    row[i]=i;
    rrow[i]=i;
  }
}

inline int swap(int i, int j)
{
  int t=row[i];
  row[i]=row[j];
  row[j]=t;

  t=rrow[row[i]];
  rrow[row[i]]=rrow[row[j]];
  rrow[row[j]]=t;
}

int main()
{
  init();
  swap(1,2);
  swap(2,4);
  return 0;
}
