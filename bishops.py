import sys

if __name__=='__main__':
  inp=sys.stdin
  for line in inp:
     n=int(line.strip())
     if n<2:
        print n
     else:
        print (n-1)<<1
