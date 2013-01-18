import sys

def gcd(a,b):
  if b==0: return a
  return gcd(b,a%b)

def solve(s):
  ans=10**len(s)
  r=gcd(ans,int(s))
  return ans/r

if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
    t=line.strip()
    if '.' in t: 
      print solve(t[t.index('.')+1:])
    else:
      print 1
