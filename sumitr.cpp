#include <ios>
#define S(n) scanf("%d",&n)
#define F(i,n) for(int i=0;i<n;++i)
main(){int A[99][99],t,n,i;S(t);F(z,t){S(n);F(x,n)F(y,x+1)S(A[x][y]);for(i=n-1;i>0;--i)F(j,i+1)A[i-1][j]+=std::max(A[i][j],A[i][j+1]);printf("%d\n",**A);}}
