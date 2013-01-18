import sys

if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
   lengths=map(lambda x: len(x),line.strip().split())
   i,n=0,len(lengths)
   seq,mseq=0,0
   while i<n:
     v=lengths[i]
     i+=1
     seq=1
     while i<n and lengths[i]==v: 
       seq+=1
       i+=1
     if seq>mseq: mseq=seq
   print mseq
