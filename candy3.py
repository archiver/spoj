import sys

if __name__=='__main__':
  inp=sys.stdin
  line=inp.readline()
  t = int(line.strip())

  for i in range(t):
    inp.readline()
    line=inp.readline()
    n=int(line.strip())
    sm=0
    for i in range(n):
      sm+=int(inp.readline().strip())
    if 0 == sm%n:
      print "YES"
    else:
      print "NO"
