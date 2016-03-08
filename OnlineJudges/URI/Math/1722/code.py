import math

def fib(n):
    A = []
    for i in range(1001):
        A.append(0)
   
	A[0] = 1
    A[1] = 1
    A[2] = 2
    for i in range(3,n):
        A[i] = A[i-1] + A[i-2]
    
    return A    

A = fib(1001)

while True:
	x,y = map(int,raw_input().split())
	if x == 0 and y == 0: break

	cont = 0
	for i in range(1, 1001):
		if( x <= A[i] and y >= A[i]):
			cont+= 1;
	print cont

