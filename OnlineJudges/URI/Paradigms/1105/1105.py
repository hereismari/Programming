while True:
	b, n = map(int, raw_input().split())
		
	if b == 0 and n == 0:
		break
		
	deb = map(int,raw_input().split())
		
	for i in range(n):
		d,c,v = map(int,raw_input().split())
		deb[d-1] -= v
		deb[c-1] += v
		
	x = True
	for i in range(n):
		if deb[i] < 0:
			x = False
			break
	if x:
		print "S"
	else:
		print "N"
