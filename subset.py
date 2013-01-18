import sys

def subsets(n,pos,cur):
  global arr
  if pos==n:
    print map(lambda x: arr[x],filter(lambda i: cur[i]==1,range(n)))
    return

  for i in range(2):
    cur[pos]=i
    subsets(n,pos+1,cur)

if __name__=='__main__':
  arr=list('abcaabaa')
  n=len(arr)
  subsets(n,0,[0]*n)
