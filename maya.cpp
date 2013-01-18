#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef unsigned long long ull;
ull vals[9];
map<string,ull> lookup;

void init()
{
  lookup["S"]=0;

  lookup["."]=1;
  lookup[".."]=2;
  lookup["..."]=3;
  lookup["...."]=4;

  lookup["-"]=5;
  lookup[".-"]=6;
  lookup["..-"]=7;
  lookup["...-"]=8;
  lookup["....-"]=9;

  lookup["--"]=10;
  lookup[".--"]=11;
  lookup["..--"]=12;
  lookup["...--"]=13;
  lookup["....--"]=14;

  lookup["---"]=15;
  lookup[".---"]=16;
  lookup["..---"]=17;
  lookup["...---"]=18;
  lookup["....---"]=19;
}

ull  output(int n)
{
  ull result=0;
  if(1==n) return vals[0];
  if(2==n) return vals[0]+20*vals[1];
  result=vals[0]+20L*vals[1];

  ull i,val=360;
  for(i=2;i<n;++i,val*=20)
     result+=(val*vals[i]);
  return result;
}

int main()
{
  int n,i;
  string str;
  init();
  while(1)
  {
    scanf("%d\n",&n);
    if(!n) break;

    for(i=0;i<n;++i)
    {
      getline(cin,str);
      vals[n-1-i]=lookup[str];
    }
   cout<<output(n)<<"\n";
  }
  return 0;
}
