#include <stdio.h>
#include <string.h>

char buf[35];

const char absurd[]="absurd\n";
const char nabsurd[]="not absurd\n";

int absurdity(int n)
{
  float lower=n*0.95;
  float upper=n*1.05;

  int loint=lower;
  int upint=upper;

  sprintf(buf,"%d",n);
  int l=strlen(buf);
  int i=l-1;
  while(i>=0 && '0'==buf[i]) --i;
  if(i<0) return 1; //0 is not absurd

  if(buf[i]=='5') return 2*i+1;
  return 2*(i+1);
}

int main()
{
   int t,c;
   scanf("%d",&t);
   int i;
   for(i=0;i<t;++i)
   {
     scanf("%d",&c);
     if(absurdity(c)) printf(absurd);
     else printf(nabsurd);
   }
   return 0;
}
