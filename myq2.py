import sys

def init():
  global value
  value={}
  value[' ']=32
  a,A=ord('a'),ord('A')
  for i in range(26):
    value[chr(a+i)]=i+1
    value[chr(A+i)]=i+51

def populate(n,m):
  global s, value, val, ind
  val[0]=value[s[0]]%m;
  ind[val[0]]=0

  for i in range(1,n):
    val[i]=(val[i-1]+value[s[i]])%m
    ind[val[i]]=i

def main():
  global val,ind,s

  inp=sys.stdin
  line=inp.readline()
  t=int(line.strip())
  init()
  for i in range(t):
    s=inp.readline()[:-1]
    line=inp.readline()
    m,k=line.strip().split()
    m,k=int(m),int(k)

    k=k%m
    n=len(s)
    val=[0]*n
    ind=[-1]*m
    populate(n,m)

    if ind[k]==-1:
      mind,mlen=-1,-1
    else:
      mind,mlen=0,ind[k]+1

    tmp,tlen=0,0

    for i in range(1,n):
      tmp=(k+val[i-1])%m
      if ind[tmp]==-1: continue

      tlen=ind[tmp]-i+1
      if tlen>mlen:
        mind,mlen=i,tlen
    
    if mind!=-1:
      print mind,mlen
    else:
      print mind

if __name__=='__main__':
   main()
