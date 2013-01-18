import sys

def solve_sub():
  if val['1/4']<=val['3/4']:
    return val['3/4']
  
  else:
    res=val['3/4']
    val['1/4']=val['1/4']-val['3/4']
    res+= (val['1/4']/4) + (1 if (val['1/4']%4!=0) else 0)
    return res

def solve():
  res=1
  res+=val['1/2']/2 + (1 if (val['1/2']%2!=0) else 0)

  if val['1/2']%2:
    #extra slice
    val['1/4']=max([val['1/4']-2,0])
  res+=solve_sub()
  return res

if __name__=='__main__':
   val={'1/2':0,'1/4':0,'3/4':0}
   inp=sys.stdin
   inp.readline()
   for line in inp:
      val[line.strip()]+=1
   print solve()
