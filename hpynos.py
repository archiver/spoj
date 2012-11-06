import sys

def sum_squares(n):
      t=str(n)
      sm=0
      for d in t:
	  sm+=int(d)**2
      return sm

def iter(s):
     cnt=0
     while s:
       s=sum_squares(s)
       cnt+=1
       if s/10==0:
         if s!=1: cnt=-1
         break
     return cnt

if __name__=='__main__':
   print iter(int(sys.stdin.readline().strip()))
