import sys
import pdb

small_maya = lambda n: [n/20,n%20]

def large_maya(n):
  res=list()
  val=360
  while n:
     nmod=(n/val)%20
     res.insert(0,nmod)
     n=n-(nmod*val)
     val=val*20
  return res

def mayan(n):
  small=small_maya(n%360)
  if n<360:
    return small
    
  newn=n-n%360
  return large_maya(newn)+small

if __name__=='__main__':
  print mayan(399)
