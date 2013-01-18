#include <stdio.h>
#include <stdlib.h>

unsigned int vals[14];
int type[2];

unsigned int  output(int n)
{
  unsigned int result=0;
  if(1==n) return vals[0];
  if(2==n) return vals[0]+20*vals[1];
  result=vals[0]+20*vals[1];

  unsigned int i,val=360;
  for(i=2;i<n;++i,val*=20)
  {
     if(vals[i])
       result+=(val*vals[i]);
  }
  return result;
}

int main()
{
  int n,i;
  char* str=(char*)malloc(8);
  char *string =str;

  while(1)
  {
    scanf("%d",&n);
    if(!n) break;

    for(i=0;i<n;++i)
    {
      type[0]=0; type[1]=0;
      string = str;
      scanf("%s",string);
      if(*string=='S') 
         vals[n-1-i]=0;
      else      
      {
         for(;*string;++string) type[*string-'-']+=1;
         vals[n-1-i]=(type[1]+type[0]*5);
      }
    }
    printf("%d\n",output(n));
  }
  return 0;
}
