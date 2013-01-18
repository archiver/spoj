from math import sqrt,ceil

def solve(k,low,high):
   l=ceil(sqrt(low))
   h=ceil(sqrt(high))



if __name__=='__main__':
   n=int(raw_input())
   for i in range(n):
     l=raw_input()
     k,low,high=l.split()
     print solve(int(k),int(low),int(high))
