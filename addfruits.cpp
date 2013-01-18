#include <stdio.h>
#include <string.h>

#define N 101
char left[N], right[N];
char lr[2*N], rl[2*N];

void solve()
{
   int n,m;
   n=strlen(left); m=strlen(right);

   int i=0,j=0,k=0;
   //left-right
   while(i<n && j<m)
   {
     lr[k]=left[i];
     k+=1;

     if(left[i]==right[j]) {i+=1; j+=1;}
     else i+=1;
   }
   if(i==n)
     for(;j<m;++j,++k) lr[k]=right[j];
   else if(j==m)
     for(;i<n;++i,++k) lr[k]=left[i];
   lr[k]='\0';

   int lr_length = k;

   i=0,j=0,k=0;
   //right-left
   while(i<n && j<m)
   {
     rl[k]=right[j];
     k+=1;
  
     if(left[i]==right[j]) {i+=1; j+=1;}
     else j+=1;
   }
   if(i==n)
     for(;j<m;++j,++k) rl[k]=right[j];
   else if(j==m)
     for(;i<n;++i,++k) rl[k]=left[i];
   rl[k]='\0';

   int rl_length = k;

   if(lr_length<rl_length)
     printf("%s\n",lr);
   else printf("%s\n",rl);
}

int main()
{
  while(scanf("%s %s",&left,&right)!=EOF) solve();
  return 0;
}

