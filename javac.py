import sys
import re

caps=re.compile(r'[A-Z]')

def convert(s):
  if(s[0].upper()==s[0]): return 'Error!'

  if '_' in s: #c++
    if(caps.findall(s)): return 'Error!'

    words=s.split('_')
    s=words[0]
    for word in words[1:]:
      if not word: return 'Error!'
      s=s+word.capitalize()
    return s

  else: #java
    chars=list(s)
    res=list()
    for e in s:
      if e==e.upper():
         res.append('_')
	 res.append(e.lower())
      else:
         res.append(e)
    return ''.join(res)

if __name__=='__main__':
  inp=sys.stdin
  for line in inp:
    print convert(line.strip())
      
