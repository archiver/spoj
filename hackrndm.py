import sys

if __name__=='__main__':
  inp=sys.stdin

  line=inp.readline()
  n,k=line.strip().split()

  k=int(k)
  line=inp.readline()
  nums=map(lambda x: int(x),line.strip().split())
  snums=set(nums)
  count=0
  for num in nums:
    if num-k in snums: count+=1

  print count
