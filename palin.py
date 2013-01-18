import sys
import pdb

def ispalin(d):
  t=str(d)
  n=len(t)
  for i in range(0,n/2):
    if t[i]!=t[n-1-i]: return False
  return True

def nextpalin(num):
  number=num+1
  while True:
    if ispalin(number): return number
    number+=1

if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
    t=line.strip()
    t=int(t)
    print nextpalin(t)
