#include <stdio.h>
#include <math.h>

/*
E; extra seconds = (year*T1)%T2
O; 0th month=(T2-E)/T3;
F; offset into 1st month = (T2-E)%T3
S; seconds in a year = (T1-O*T3)
*/

int T1,T2,T3; //global variables

int days(int year, int month)
{
  int E=((year-1)*T1)%T2;
  int F=E>0?(T2-E):0;

  if(!month) //0th month
    return F/T3;
  
  int start = F+(month-1)*T2; //start second for current month
  if(start>=T1) return 0; //no such month

  int end = F+month*T2; //start second for next month
  if(end>=T1) return ((year*T1)%T2)/T3; //last month

  start=(start-(start%T3))/T3;//start day current month
  end=(end-(end%T3))/T3; //start day of next month

  return end-start; //number of days in the month
}

int main()
{
  int t,q;
  int y,m;
  int i,j;
  scanf("%d",&t);
  for(i=0;i<t;++i)
  {
    scanf("%d %d %d",&T1,&T2,&T3);
    scanf("%d",&q);
    for(j=0;j<q;++j)
    {
      scanf("%d %d",&y,&m);
      printf("%d\n",days(y,m));
    }
  }
  return 0;
}
