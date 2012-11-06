import sys

def add_rev(a,b):
  rev=lambda x: int(''.join(reversed(x)))
  return rev(str(rev(a)+rev(b)))

if __name__=='__main__':
  s=sys.stdin
  cases=int(s.readline().strip())
  for i in range(cases):
    l=s.readline()
    a,b=l.strip().split()
    print add_rev(a,b)
