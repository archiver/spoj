#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
typedef stack<int> si;
typedef queue<int> qi;

bool solve(qi &l)
{
   int t;
   si r;

   int i=1;
   bool found=false;
   while(!l.empty())
   {
      t=l.front();
      if(t==i) { found=true; break; }
      r.push(t);
      l.pop();
   }
   if(!found) return false;
   l.pop();
   i+=1;

   while(!l.empty() && !r.empty())
   {
      if(l.front()==i)
	 l.pop();
      else if(r.top()==i)
	 r.pop();
      else
      {  
         found=false;
	 while(!l.empty())
	 {
	    t=l.front();
	    if(t==i) { found=true; break; }
	    r.push(t);
	    l.pop();
	 }
         if(!found) return false;
	 l.pop();
      }
      i+=1;
   }
   return true;
}

int main()
{
   int n,i,t;
   while(1)
   {
      scanf("%d",&n);
      if(!n) break;

      qi l;
      for(i=0;i<n;++i)
      {
	 scanf("%d",&t);
	 l.push(t);
      }
      if(solve(l))
	 printf("yes\n");
      else
	 printf("no\n");
   }
   return 0;
}
