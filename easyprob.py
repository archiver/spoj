import sys

nums=[137, 1315, 73, 136, 255, 1384, 16385]

def represent(num):
  if num==0: return "0"

  s=bin(num)[2:]
  n=len(s)
  ans=list()
  for pos in map(lambda i: n-i-1,filter(lambda x: s[x]=='1',range(n))):
   if pos==1: 
     ans.append('2')
   else:
     ans.append('2(%s)'%(represent(pos)))
   
  return '+'.join(ans)

if __name__=='__main__':
  for num in nums:
    print '%d=%s'%(num,represent(num))
