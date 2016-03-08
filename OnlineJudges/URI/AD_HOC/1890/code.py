n = int(raw_input())

while n > 0:
	x, y = map(int, raw_input().split())
	if x and y != 0:
		print pow(26,x)*pow(10,y)
	else:
		print 0
	n -= 1
