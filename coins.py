import sys

coins={0:0,1:1,2:2}

def maxchange(n):
  if n in coins:
     return coins[n]
  coins[n]=max([n,maxchange(n/2)+maxchange(n/3)+maxchange(n/4)])
  return coins[n]

if __name__=='__main__':
  for line in sys.stdin:
     n=int(line.strip())
     print maxchange(n)
