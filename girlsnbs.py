import sys

def solve(g,b):
  if not g: return b
  elif not b: return g
  elif g==1: return (b+1)/2
  elif b==1: return (g+1)/2
  elif g==b: return 1

  else:
    if g<b:
      n=b/(g+1)
      if b%(g+1):
        n+=1

    else:
      n=g/(b+1)
      if g%(b+1):
        n+=1

    return n

if __name__=='__main__':
  inp=sys.stdin
  for line in inp:
    g,b=line.strip().split()
    g,b=int(g),int(b)
    if g==-1 and b==-1: break
    print solve(g,b)
