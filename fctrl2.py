import sys

def solve(k):
   global flist
   flist=[1]*(k)
   
   for i in range(1,k):
     flist[i]=(i+1)*flist[i-1]

def readinp():
   global flist
   inp=sys.stdin
   inp.readline()
   for line in inp:
     ind=int(line.strip())-1
     print flist[ind]

if __name__=='__main__':
  flist=None
  solve(100)
  readinp()
