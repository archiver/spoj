import sys

def convert(num,bas):
   res=0
   rbas=1 #rolling base
   for n in reversed(num):
     res+=n*rbas
     rbas=rbas*bas
   return res

def process(l):
  global digits,dicts
  res=0

  num=map(lambda c: dicts[c],list(l))
  bas=max(num)+1

  for b in range(bas,len(digits)+1):
    res+=convert(num,b)
  return res
  
def main():
  global digits,dicts
  
  inp=sys.stdin
  line=inp.readline()
  tm=line.strip()
  digits=list(line.strip())
  dicts=dict(zip(digits,range(len(digits))))

  while True:
   line=inp.readline()
   if not line: break

   tm=line.strip()

   if tm:
     print process(tm)

   else:
     while line and not tm:
       line=inp.readline()
       tm=line.strip()
     
     if not line: break

     digits=list(tm)
     dicts=dict(zip(digits,range(len(digits))))
     print
   
if __name__=='__main__':
  sys.exit(main())
