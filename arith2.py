import sys
import re

ops=re.compile(r"([-+*/=])")

def evaluate(s):
  vals=re.split(ops,s)[:-2]
  vals=map(lambda x: x.strip(), vals)
  if(len(vals)==1): 
     print vals[0]
     return

  res=eval('%s%s%s'%(vals[0],vals[1],vals[2]))
  del vals[:3]

  while vals:
    res=eval('%d%s%s'%(res,vals[0],vals[1]))
    del vals[:2]
  
  print res

if __name__=='__main__':
  inp=sys.stdin
  line=inp.readline()
  while True:
    line=inp.readline()
    if not line: break
    line=inp.readline()
    evaluate(line.strip())
