n = int(raw_input())

counter = {}

for i in range(1,2001):
	counter[i] = 0

for i in range(n):
	x = int(raw_input())
	counter[x] += 1

for i in range(1,2001):
	if counter[i] != 0:
		print str(i) + " aparece " + str(counter[i]) + " vez(es)"
