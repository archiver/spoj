#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int rotate(string barrel, int k, int n)
{
   k=(n+k)%n;
   if(!k) 
      return barrel[0]=='0'?1:0;

   int pos=0,start=0;
   char buf=0,pval=0;
   int i=0;

   while(i<n)
   {
      pos=start;
      pval=barrel[pos];
      do
      {
	 pos=(pos+k)%n;
	 buf=barrel[pos];
	 barrel[pos]=pval;
	 pval=buf;
	 i+=1;
      }while(pos!=start);
      start+=1;
   }

   return barrel[0]=='0'?1:0;
}

int solve(string& barrel)
{
   int n=barrel.size();
   int zeros=0,favorable=0;

   for(int i=0;i<n;++i) 
   {
      if(barrel[i]=='0') 
      {
	 zeros+=1;
	 favorable+=rotate(barrel,-i+1,n);
      }
   }

   float rand_prob=(zeros*1.0/n);
   float rot_prob=(favorable*1.0/zeros);

   if(rand_prob==rot_prob)
      printf("EQUAL\n");
   else if(rand_prob>rot_prob)
      printf("ROTATE\n");
   else 
      printf("SHOOT\n");
}

int main()
{
   string barrel;
   cin>>barrel;
   solve(barrel);
   return 0;
}
