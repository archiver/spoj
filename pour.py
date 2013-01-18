import sys

explanation = \
'''
         4  6                  2   4    6          2*(b/a)
  1  ((),2a,..)          -2    (b-a,b-2a,b-3a

     (p+1),_+2,_+2..         (p+2)+2   _+2         2*(b+phi)/a
  r1 (a+r1,2a+r1,..)    a-r1 (b-(a-r1),...
'''

def possible(a,b):
   global rems,lrems,rrems,lprev,rprev

   a,b=sorted([a,b])

   phi=0
   rems=[0]
   while True:
     phi=(b+phi)%a
     if not phi: break
     rems.append(phi)

   n=len(rems)
   rrems=dict(zip(rems[1:],range(n-1)))
   lrems=dict(zip(rems[:-1],range(n-1)))

   rprev=[0]*n
   rprev[0]=-2
   for i in range(1,n):
     rprev[i] = (rprev[i-1]+2)+2*((b+rems[i-1])/a)
   
   lprev=[1]*n
   for i in range(1,n):
     lprev[i]=rprev[i]

def moves(a,b,c):
  global rems,lrems,rrems,lprev,rprev
  
  a,b=sorted([a,b])
  possible(a,b)
  if c>b or c<=0: return float('inf')
  if c==a or c==b: return 1
  else:
    lmoves,rmoves=float('inf'),float('inf')
    if c%a in lrems:
      val= 2*(((c-c%a)/a)-1)
      if val>=0:
        lmoves= (lprev[lrems[c%a]]+1)+val

    if c%a in rrems:
      val= 2*((b-c+(b-c)%a)/a)
      rmoves = (rprev[rrems[c%a]]+2)+ val
    return min([lmoves,rmoves])

if __name__=='__main__':
   inp=sys.stdin
   n=int(inp.readline().strip())
   for i in range(n):
     a=int(inp.readline().strip())
     b=int(inp.readline().strip())
     c=int(inp.readline().strip())
     res=moves(a,b,c)
     if res==float('inf'): print -1
     else: print res
