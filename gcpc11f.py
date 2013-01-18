import sys

def init():
  global chars
  chars=[0]*26
  for i in range(26):
    chars[i]=chr(ord('A')+i)

def calculate(s):
  global chars
  norm = ''.join((s.strip().split()))
  vals=dict(zip(chars,[0]*26))
  for e in norm:
    vals[e]+=1
  arr=sorted(vals.items(),key=lambda x: (x[1],x[0]), reverse=True)
  if arr[0][1]==arr[1][1]:
    return -1
  else:
    return (ord(arr[0][0])-ord('E'))%26

def solve(s):
  d=calculate(s)
  if d==-1:
    print "NOT POSSIBLE"
    return 
  else:
    print d,
    arr = s.split()
    for i in range(len(arr)):
      arr[i]= ''.join(map(lambda x: chr((ord(x)-ord('A')-d)%26+ord('A')),arr[i]))
    print ' '.join(arr)
      

if __name__=='__main__':
  init()
  inp=sys.stdin
  inp.readline()
  for line in inp:
    solve(line.strip())
