while True:
	n,m = raw_input().split()
	answer1 = ""
	if n == '0' and m == '0':
		break
	for e in m:
		if e != n:
			answer1 += e
	i = 0
	answer1 = '0' + answer1
	while answer1[i] == '0' and i != len(answer1) -1:
		i += 1
	print answer1[i:]
