from collections import namedtuple
import sys

Info=namedtuple('Info',('start','height'))

def maxarea(hist): 
  stack=list()
  top=lambda : stack[-1]
  area=0

  for pos,height in enumerate(hist):
     start=pos

     while True:
        if not stack or height>top().height:
           stack.append(Info(start,height))

        elif stack and height<top().height:
          start,h=stack.pop()
          area=max(area,h*(pos-start))
          continue
        break
     print area
  pos+=1

  for start,height in stack:
     area=max(area,height*(pos-start))
     print area
  return area

if __name__=='__main__':
   s=sys.stdin
   for line in s:
     hist=map(lambda x: int(x), line.strip().split())
     if hist[0]==0: break
     print maxarea(hist[1:])
