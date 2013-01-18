import sys

if __name__=='__main__':
  inp=sys.stdin
  while True:
    line=inp.readline()
    if not line: break
    a=set(list(line.strip()))
    line=inp.readline()
    b=set(list(line.strip()))
    print ''.join(sorted(a.intersection(b)))
