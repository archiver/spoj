
def print_all():
 n,t=3,0
 arr=[1,0,4]

 a=sum(arr)
 f = lambda i: (((n-1)**t -(-1)**t)*a)/n + (-1)**t*arr[i]
 
 for t in range(0,7):
   for i in range(n):
      print f(i),
   print

print_all()
