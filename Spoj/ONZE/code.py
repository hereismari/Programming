while True:
	s = raw_input()
	if s == "0": break

	answer = 0
	for i in range(len(s)-1,-1,-1):
		if(i%2 == 0):
			answer += int(s[i])
		else : answer -= int(s[i])

	if(answer % 11 == 0): print s + " is a multiple of 11."
	else: print s + " is not a multiple of 11."
