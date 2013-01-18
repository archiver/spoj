#include <stdio.h>
#include <string.h>

#define N 200
char barrel[N];

int solve(char barrel[N], int n)
{
   int zeros=0,favorable=0;
   int i;
   for(i=0;i<n;++i) 
   {
      if(barrel[i]=='0') 
      {
	 zeros+=1;
	 favorable+=(barrel[(n+i-1)%n]=='0'?1:0);
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
   scanf("%s",barrel);
   solve(barrel,strlen(barrel));
   return 0;
}
