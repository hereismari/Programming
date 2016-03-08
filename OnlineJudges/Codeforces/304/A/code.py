k,n,w = map(int,raw_input().split())

cust = k*((w*(w+1))/2)

if cust <= n: print 0

else: print cust - n
