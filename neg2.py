import sys

def rem(n,d):
  if n==0: return (0,'0')
  if n==1: return (0,'1')
  if n==-1: return (0,'11')

  r = n - d*(n/d)
  if r<0:
    r=r-d
    n = (n-r)/d
  else:
    n = n/d

  return (n,r)

def convert(n):
  res=list()
  if not n: return '0'

  while n:
    n,r=rem(n,-2)
    res.insert(0,str(r))
  return ''.join(res)

if __name__=='__main__':
   inp=sys.stdin
   line=inp.readline()
   n=int(line.strip())
   print convert(n)
