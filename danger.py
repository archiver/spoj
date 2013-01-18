import sys
import pdb

def danger(n):
  l=range(1,n+1)
  m=[1]*n
 
  start=0
  while m!=[0]*n:
     pos=start
     
     while not m[start]: start=(start+1)%n
     print map(lambda x:l[x],filter(lambda i:m[i]==1,range(n)))
     pdb.set_trace()

if __name__=='__main__':
  danger(10)
