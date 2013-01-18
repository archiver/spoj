import sys

cases = ["TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"]

def print_res(n,vals):
  global cases
  print n,
  for case in cases:
    print vals[case],
  print

def solve(n,s):
  global cases
  vals=dict(zip(cases,[0]*8))
  for i in range(0,len(s)-2):
     vals[s[i:i+3]]+=1
  print_res(n,vals)

if __name__=='__main__':

   inp=sys.stdin
   line=inp.readline()
   t=int(line.strip())

   for i in range(t):
     n=int(inp.readline().strip())
     line=inp.readline()
     solve(n,line.strip())

   
