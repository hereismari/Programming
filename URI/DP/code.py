n = int(raw_input())

for i in range(n):
	x = int(raw_input())
	xbin = bin(x)
	i = 1

	j = 0
	k = 1
	answer = 0
	for e in range(len(xbin)-2,1,-1):
		print xbin[e],
		if(xbin[e] == '1'): answer += j + k
		tmp = k
		k += j
		j = tmp
		
	print answer
