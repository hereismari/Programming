n = int(raw_input())
s = raw_input()

x = 0
for e in s:
	if e == '0':
		x += 1
	else:
		x -= 1

print abs(x)
