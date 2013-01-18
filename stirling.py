import math
import sys

pi = 3.1415926535897932385
e = 2.71828182845904523536
const = 0.5*math.log(math.sqrt(pi*2),10)

def length(n):
  global const
  if 0==n or 1==n:
    print 1
    return
  print int(math.ceil(0.5*math.log(n,10) + n*math.log(n,10) - n*math.log(e,10) + const))

if __name__=='__main__':
   inp=sys.stdin
   inp.readline()
   for line in inp:
     length(int(line.strip()))
