n = int(raw_input())

x = 1
i = 0
while i < n:
	x *= 3
	x = x % (pow(2,31)-1)
	i += 1

print x
