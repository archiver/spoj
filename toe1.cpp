#include <stdio.h>
int tt[3][3];
int count[3];

int whowon()
{
  //0 is 0, 1 is x, . is 2

  int i,j;
  int cnt[3];
  int state=0;

  count[0]=0;count[1]=0;count[2]=0;

  for(i=0;i<3;++i) //row check
  {
    cnt[0]=0;cnt[1]=0;cnt[2]=0;
    for(j=0;j<3;++j)
    {
      cnt[tt[i][j]]+=1;
      count[tt[i][j]]+=1;
    }
    if(cnt[0]==3) state|=1<<0;
    if(cnt[1]==3) state|=1<<1;
  }

  for(j=0;j<3;++j) //col check
  {
    cnt[0]=0;cnt[1]=0;cnt[2]=0;
    for(i=0;i<3;++i)
      cnt[tt[i][j]]+=1;
    if(cnt[0]==3) state|=1<<0;
    if(cnt[1]==3) state|=1<<1;
  }

  cnt[0]=0;cnt[1]=0;cnt[2]=0;
  for(i=0;i<3;++i) //right diag check
    cnt[tt[i][i]]+=1;
  if(cnt[0]==3) state|=1<<0;
  if(cnt[1]==3) state|=1<<1;
   

  cnt[0]=0;cnt[1]=0;cnt[2]=0;
  for(i=0;i<3;++i) //left diag check
    cnt[tt[i][2-i]]+=1;

  if(cnt[0]==3) state|=1<<0;
  if(cnt[1]==3) state|=1<<1;
    
  return state;
}

bool solve()
{
  int state=whowon();

  if(state==3) return false; //both could not have won
  if(count[1]<count[0]) return false;

  if(state==2) //x won 
    return (count[1]==count[0]+1);
  else if(state==1) //o won
    return (count[1]==count[0]);
  else //no win
    return (count[1]==count[0]+1 || count[1]==count[0]);
}

int main()
{
  int t,i,j;
  char s[4];

  scanf("%d",&t);
  while(t--)
  {
    for(i=0;i<3;++i)
    {
      scanf("%s",&s);
      for(j=0;j<3;++j)
        tt[i][j]=(s[j]=='O'?0:(s[j]=='X'?1:2));
    }
    if(solve())
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
