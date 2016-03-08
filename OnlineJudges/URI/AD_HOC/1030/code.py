import math

def f(j,k):
	if j == 1:
		return 1
	else: 
		return (k-1 + (f(j-1,k))) % j + 1

n = int(raw_input())

for i in range(n):
	j,k = map(int,raw_input().split())
	print f(j,k)
