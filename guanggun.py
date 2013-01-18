import sys

vals={}

def init():
  for i in range(9):
     vals[i]=i*i

def calculate(n):
  return 37*(n/9)+44*(n/9)+vals[n%9]

if __name__=='__main__':
  inp=sys.stdin
  init()
  for line in inp:
    print calculate(int(line.strip()))
