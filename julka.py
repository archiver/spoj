import sys

if __name__=='__main__':
   inp=sys.stdin
   for i in range(10):
     line=inp.readline()
     n=int(line.strip())
     line=inp.readline()
     k=int(line.strip())
     x=(n+k)/2
     print x
     print x-k
