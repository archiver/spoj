#include <stdio.h>
#include <string.h>
#define N 200
char visited[N];

void process(char s[N], int c, int l)
{
   int i=0,j=0;
   char t;
   int other;
   for(i=c;i<l;i+=c<<1)
   {
      for(j=i;j<i+c/2;++j)
      {
	 other=i+c-1-(j-i);
	 t=s[j];
	 s[j]=s[other];
	 s[other]=t;
      }
   }
}

void transpose(char s[N], int c, int l)
{
   //  char visited[N]={0}; //caused a lot of issues due to non-initialization

   int pos=0,start=0;
   char pval,buf;

   int n=c;
   int m=(l/c);

   while(start<l)
   {
      pos=start;
      pval=s[pos];
      do
      {
	 pos=(pos%n)*m+(pos/n);
	 buf=s[pos];
	 s[pos]=pval;
	 pval=buf;
	 visited[pos]=1;
      }while(pos!=start);
      while(start<l && visited[start]) start+=1;
   }
}

int main()
{
   char s[N];
   int c,n;
   while(1)
   {
      scanf("%d",&c);
      if(!c) break;
      scanf("%s",&s);
      n=strlen(s);
      process(s,c,n);
      transpose(s,c,n);
      printf("%s\n",s);
   }
   return 0;
}
