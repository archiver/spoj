import calendar
n,c=input(),lambda x:int(x,2)
while n:t=bin(input())[2:].zfill(23);print c(t[18:]),calendar.month_name[c(t[14:18])],c(t[:14]);n-=1
