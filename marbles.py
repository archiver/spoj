import sys

def solve(n,k):
#(n-1)C(k-1)

   if k==1: return 1

   N=n-1
   R=min(k-1,n-k)

   num=range(N,N-R,-1)
   den=range(R,0,-1)
   
   return reduce(lambda x,y: x*y,num,1)/reduce(lambda x,y:x*y,den,1)
   
if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
    n,k=line.strip().split()
    n,k=int(n),int(k)
    if n<k: print 0
    elif n==k: print 1
    else: print solve(n,k)
