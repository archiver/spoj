import sys

if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
    a,b=line.strip().split()
    a,b=int(a),int(b)
    print a*b
