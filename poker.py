import sys
from collections import Counter

first = "AKQJT98765432"
second = "KQJT98765432A"

fcompare= {'A':14,'K':13,'Q':12,'J':11,'T':10,'9':9,'8':8,'7':7,'6':6,'5':5,'4':4,'3':3,'2':2}
scompare= {'K':13,'Q':12,'J':11,'T':10,'9':9,'8':8,'7':7,'6':6,'5':5,'4':4,'3':3,'2':2,'A':1}

def state(lst):
  global first,second,fcompare,scompare
  
  number = ''.join(map(lambda x:x[0],lst))
  house = ''.join(map(lambda x:x[1],lst))

  ncount=sorted(map(lambda x:x[1],Counter(number).items()))
  hcount=sorted(map(lambda x:x[1],Counter(house).items()))

  lst1 = sorted(lst,cmp=lambda x,y: -fcompare[x[0]]+fcompare[y[0]])
  lst2 = sorted(lst,cmp=lambda x,y: -scompare[x[0]]+scompare[y[0]])

  number1 = ''.join(map(lambda x: x[0],lst1))
  number2 = ''.join(map(lambda x: x[0],lst2))
  
  if hcount==[5]:
    if number1 in "AKQJT":
      return "royal flush"
 
    elif (number1 in first) or (number2 in second):
      return "straight flush"
  
  if ncount==[1,4]:
   return "four of a kind"

  if ncount==[2,3]:
   return "full house"

  if hcount==[5]:
   return "flush"

  if (number1 in first) or (number2 in second):
   return "straight"
  
  if 3 in ncount:
    return "three of a kind"

  if ncount==[1,2,2]:
   return "two pairs"

  if 2 in ncount:
   return "pair"
  
  return "high card"

if __name__=='__main__':
  inp=sys.stdin
  inp.readline()
  for line in inp:
    lst=line.strip().split()
    print state(lst)
