#include <stdio.h>
#include <string.h>

#define N 100000
char accounts[N][34];

int ind[N];
int calc[N];

void print(int n)
{
  for(int i=1;i<n;++i)
    printf("%s\n",accounts[ind[i]]);
} 

void print_res(int n)
{   
  int i=0,cnt=0;
  for(i=1;i<=n;++i)
  {
    cnt=1;
    while(i<n && !strcmp(accounts[ind[i]],accounts[ind[i-1]]))
    {
      i+=1;
      cnt+=1;
    }
    printf("%s%d\n",accounts[ind[i-1]],cnt);
  }
}

inline void radix_step(int pos, int n)
{
   if(accounts[0][pos]==' ') return;
   
   int i,j;
   int repr;

   int buf[]={0,0,0,0,0,0,0,0,0,0};

   for(i=0;i<n;++i)
   {
     repr=accounts[ind[i]][pos]-'0';
     buf[repr]+=1;
   }

   for(j=1;j<10;++j)
     buf[j]+=buf[j-1];

   for(i=n-1;i>=0;--i)
   {
     repr=accounts[ind[i]][pos]-'0';
     calc[buf[repr]-1]=ind[i];
     buf[repr]-=1;
   }

   for(i=0;i<n;++i)
     ind[i]=calc[i];  
}

void solve(int n)
{
  int i=0;
  for(i=0;i<n;++i) ind[i]=i;
  for(i=31;i>=0;--i)
    radix_step(i,n);
  print_res(n);
}


int main()
{
   int t,n;
   int i;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d\n",&n);
     for(i=0;i<n;++i)
     {
       fgets(accounts[i],34,stdin);
       accounts[i][32]='\0';
     }
     solve(n);
     printf("\n");
   }
   return 0;
}
