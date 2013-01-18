#include <stdio.h>
#include <string.h>

char buf[35];
const char absurd[]="absurd\n";
const char nabsurd[]="not absurd\n";

int absurdity(int n)
{
  sprintf(buf,"%d",n);
  int l=strlen(buf);
  int i=l-1;
  while(i>=0 && '0'==buf[i]) --i;
  if(i>=0)
  {
    if(buf[i]=='5') return 2*i+1;
    return 2*(i+1);
  }
  else return 0;
}

int isabsurd(int c)
{
  float lower=c*0.95;
  float upper=c*1.05;

  int loint=lower;
  int s = (lower==loint)?loint:loint+1;

  int cabs=absurdity(c);

  for(;lower<=s && s<=upper;++s)
    if(absurdity(s)<cabs) return 1;

  return 0;
}

int main()
{
   int t,c;
   scanf("%d",&t);
   int i;
   for(i=0;i<t;++i)
   {
     scanf("%d",&c);
     if(isabsurd(c)) printf(absurd);
     else printf(nabsurd);
   }
   return 0;
}
