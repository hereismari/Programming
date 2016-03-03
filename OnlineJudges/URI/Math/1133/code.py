n1 = int(raw_input())
n2 = int(raw_input())

if n2 < n1:
	aux = n2
	n2 = n1
	n1 = aux

x = n1 + 1

while x % 5 != 2 and x % 5 != 3:
	x += 1

while x < n2:
	print x
	if x % 5 == 2:
		x += 1
	elif x % 5 == 3:
		x += 4

