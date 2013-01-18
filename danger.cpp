#include <stdio.h>
#include <string.h>
#define N 5
char name[N];

const int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
const int S[] = {1, 2, 4, 8, 16};

inline int hbit(int v)
{
    int i;
    register unsigned int r = 0;
    for (i = 4; i >= 0; i--)
    {
	if (v & b[i])
	{
	    v >>= S[i];
	    r |= S[i];
	}
    }
    return r;
}

int power(int n, int e)
{
  int res=n,i=0;
  for(i=0;i<e;++i)
    res=res*10;
  return res;
}

int solve()
{
  int n=0;
  n=name[0]-'0';
  n=(name[1]-'0')+10*n;
  n=power(n,name[3]-'0');
  int pos = hbit(n);
  int residue = n-(1<<pos);
  return (2*residue+1);
}

int main()
{
    while(true)
    {
	scanf("%s",&name);
	if(strcmp(name,"00e0")==0) break;
	printf("%d\n",solve());
    }
    return 0;
}
