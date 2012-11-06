import os
import pdb

def sqrt(a):
   nxt=lambda x: 0.5*x+0.5*(a/x)
   x=a/2

   while x:
     y=nxt(x)
     if y==x: break
     x=y

   return x

def bins(a,l,r):
   m=(l+r)/2
   prod=m*m
   if prod==a: return m
   if prod<a: return bins(a,m,r)
   else: return bins(a,l,m)

if __name__=='__main__':
  print bins(81,0,41)

