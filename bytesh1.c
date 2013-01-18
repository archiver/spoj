#include <stdio.h>

#define N 100000
#define D 10000

int beads[N+1];

int calculate()
{
  beads[0]=1;
  beads[1]=1;
  beads[2]=2;

  int i=3;
  int temp=4;

  for(;i<=N;++i)
  {
    beads[i]=2*temp;
    beads[i]=(2*D+beads[i]-beads[i-1]-beads[i-2])%D;
    temp=(temp+beads[i])%D;
  }
  
/*
  printf("#include <stdio.h>\n int beads[] = {");
  for(i=0;i<N;++i)
    printf("%d,",beads[i]);
  printf("%d};\n",beads[i]);
*/

}

int main()
{
  int t,b;
  calculate();

  scanf("%d",&t);
  int i;

  for(i=0;i<t;++i)
  {
    scanf("%d",&b);
    printf("%d\n",beads[b]);
  }

  return 0;
}
