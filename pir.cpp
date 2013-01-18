#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<float> vf;
typedef vector<vf> vvf;

#define pb push_back

float determinant(vvf &mat, int n)
{
   if(n==1) return mat[0][0];
   
   vvf sub;
   float res=0.0;
   int i,j;
   for(int i=0;i<n;++i)
   {
      sub.clear();
      for(j=0;j<n;++j)
      {
        if(j==i) continue;
	sub.pb(vf(mat[j].begin()+1,mat[j].end()));
      }
      res+=((i&1?-1:1)*mat[i][0]*determinant(sub,n-1));
   }
   return res;
}

float solve(int a, int b, int c, int d, int e, int f)
{
  vvf mat;
  int matrix[5][5]= \
  {{0,1,1,1,1},
  {1,0,a*a,b*b,c*c},
  {1,a*a,0,d*d,e*e},
  {1,b*b,d*d,0,f*f},
  {1,c*c,e*e,f*f,0},
  };
  
  for(int i=0;i<5;++i)
    mat.pb(vf(matrix[i],matrix[i]+5));

  float val=determinant(mat,5);
  val=val/288.0;
  return sqrt(val);
}

int main()
{
   int a,b,c,d,e,f;
   int t;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
     printf("%.4f\n",solve(a,b,c,d,e,f));
   }
   return 0;
}
