#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

typedef vector<int> vi;
#define pb push_back

int changes(vi cur, int n)
{
  int i=0,pos;
  for(i=n-1;i>=0;--i)
    if(cur[i]) break;
  if(i<0) return 0; //final state
  pos=i;

  vi pref(cur);
  for(;i>=0;--i) //flip prefix
    pref[i]=pref[i]^1;

  int pchange = changes(pref,n)+1;
/*
  copy(cur.begin(),cur.end(),ostream_iterator<int>(cout," "));
  printf("\n");
 
  copy(pref.begin(),pref.end(),ostream_iterator<int>(cout," "));
  printf("\n");

  printf("p: %d\n",pchange);
*/

  cur[pos]=cur[pos]^1; //flip index
  int ichange = changes(cur,n)+1;
/*  
  printf("i: %d\n",ichange);
*/
  return min(pchange,ichange);
}

int linear(vi cur

int main()
{
  vi cur;
  for(int i=0;i<1000000;++i)
    cur.pb(1);

  printf("%d\n",changes(cur,cur.size()));
  return 0;
}

