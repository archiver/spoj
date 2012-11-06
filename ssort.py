import sys
from bisect import bisect_left

def sscore(arr):
   n=len(arr)
   aux=(map(lambda x: (arr[x],x), range(n)))
   aux.sort(key=lambda x: x[0])

   vals=map(lambda x: x[0],aux)
   inds=map(lambda x: x[1],aux)
   
   score=0
   if arr[-1]!=aux[-1][0]:
      l=n-1
      s=inds[0]

      inds[0]=l
      inds[bisect_left(vals,arr[l])]=s

      score+=(arr[l]+arr[s])
      arr[s],arr[l]=arr[l],arr[s]
   print arr
   
   for i in range(n-1,-1,-1):
      if arr[i]==vals[i]: continue

      l=inds[i]
      s=inds[0]

      inds[i],inds[0]=inds[0],inds[i]

      score+=(arr[l]+arr[s])
      arr[s],arr[l]=arr[l],arr[s]
      print arr
   print score

if __name__=='__main__':
   arr=[1,8,9,7,6]
   sscore(arr)

