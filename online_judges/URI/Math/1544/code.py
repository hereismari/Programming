def answer(n,m):
	multi = 1
	e = n - m + 1
	while(e <= n):
		multi *= e
		e += 1
#	print multi
	while(multi % 10 == 0 ): multi /= 10
	return multi % 10

while True:

	try:
		n,m=map(int,raw_input().split())
	except EOFError:
		break
	
	print answer(n,m)
	
