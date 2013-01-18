import sys
import pdb

def subsums(arr):
  val=sum(arr)
  sarr=[0]*(val+1)
  sarr[0]=1
  
  for e in arr:
    for v in range(val,e-1,-1):
      sarr[v]=sarr[v]|sarr[v-e]

  print sarr[100]

if __name__=='__main__':
  arr=[13,17,42,9,23,57]
  subsums(arr)
