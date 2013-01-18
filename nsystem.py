import sys

conv = ['i','x','c','m']
vals = {'i':1,'x':10,'c':100,'m':1000}
digits = {'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}

def to_mcxi(n):
  global conv

  s=str(n)
  l=len(s)
  res=list()

  for e in s:
    l-=1
    if e=='0': continue
    elif e=='1': res.append(conv[l])
    else: res.append(e+conv[l])

  return ''.join(res)

def from_mcxi(s):
  global vals, digits
  i,l=0,len(s)
  res=0
  while i<l:
   if s[i] in digits:
     res+=(digits[s[i]])*vals[s[i+1]]
     i+=2
   else:
     res+=vals[s[i]]
     i+=1
  return res

if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
    nums=map(lambda x:from_mcxi(x),line.strip().split())
    print to_mcxi(sum(nums))
