import pdb

def value(s):
  arr=map(lambda x:ord(x),list(s))
  n=len(arr)
  v=0
  for i in range(1,n):
    v+=(arr[i]-arr[i-1])
  return v

def rot_value(s):
  n=len(s)
  s=s*2
  for i in range(n):
    temp=s[i:i+n]
    print temp,value(temp)
    #pdb.set_trace()

if __name__=='__main__':
  s='amandamanda'
  rot_value(s)



