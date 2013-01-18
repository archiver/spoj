import sys

dpos = lambda i,n: (i*10**(n-1) * (45*n + 5*(i-1)))+i

def sumdigs(n):

  l=len(n)   
  ans=0
  for i in range(l-1):
    ans += dpos(int(n[i]),l-i-1) + int(n[i])*(int(n[i+1:]))
  ans+=(int(n[l-1])*(int(n[l-1])+1))/2
  return ans

if __name__=='__main__':
  inp=sys.stdin
  for line in inp:
    a,b=line.strip().split()
    if a=='-1' and b=='-1': break
    a=int(a)
    left = 0 if not a else sumdigs(str(a-1))
    right = sumdigs(b)
    print right-left
