import sys

l=-1
r=2

def lsubsets(n,pos,cur):
  global s
  vals=map(lambda x: s[x],filter(lambda i:cur[i]==1,range(n)))
  print vals, sum(vals)
  if pos==n: return

  for i in range(pos,n):
     cur[i]=1
     lsubsets(n,i+1,cur)
     cur[i]=0
    
if __name__=='__main__':
  n=3
  s=[-2,1,3]
  lsubsets(n,0,[0]*n)
