import sys

def recover(s):
  plus=s.index('+')
  equal=s.index('=')
  start=s.index('ma')
  end=s.index('la')
  
  n=[0,0,0]

  n[0]=s[:plus].strip()
  n[1]=s[plus+1:equal].strip()
  n[2]=s[equal+1:].strip()

  if start<equal:
     if end>plus: 
       #pos=1
       res='%s + %s = %s'%(n[0],str(int(n[2])-int(n[0])),n[2])

     else: 
       #pos=0
       res='%s + %s = %s'%(str(int(n[2])-int(n[1])),n[1],n[2])
  else: 
    #pos=2
    res='%s + %s = %s'%(n[0],n[1],str(int(n[0])+int(n[1])))
  
  print res

if __name__=='__main__':
  s=sys.stdin
  cases = int(s.readline().strip())
  s.readline()
  for case in range(cases):
     line=s.readline().strip()
     s.readline()
     recover(line)
