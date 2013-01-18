#include <stdio.h>
#include <set>
using namespace std;

set<int> s;
set<int>::iterator st;

void insert(int a)
{
  s.insert(a);
}

void del(int a)
{
  st = s.find(a);
  if(st!=s.end())
    s.erase(st);
}

int count(int a)
{
  st = u
}

int main()
{
  s.clear();

}
