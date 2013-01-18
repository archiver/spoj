import sys

seq=list()

def pattern(n):
  global seq
  seq=[0]*(n+1)
  diff=set([0])

  for i in range(1,n+1):
    left=seq[i-1]-i
    right=seq[i-1]+i
    if left>0 and left not in diff:
      seq[i]=left
    else:
      seq[i]=right
    diff.add(seq[i])

if __name__=='__main__':
  pattern(500000)
  inp=sys.stdin
  for line in inp:
    n=int(line.strip())
    if n==-1: break
    print seq[n]
