import sys
from bisect import bisect_left

n=35000
vals=[0]*n

def calculate():
  global vals,n

  res=0
  for i in range(2,n+1):
    res+=1.0/i
    vals[i-1]=res

if __name__=='__main__':
  calculate()
  inp=sys.stdin
  for line in inp:
    val=float(line.strip())
    if val==0: break
    pos=bisect_left(vals,val)
    print '%d card(s)'%(pos)
