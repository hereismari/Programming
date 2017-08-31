
fat = [1,1,2,6,24,120,720,5040,40320,362880]

while True:
	num = raw_input();
	if(num == "0"): break
	
	answer = 0
	length = len(num)
	for e in num:
		answer += int(e)*fat[length]
		length -= 1

	print answer
