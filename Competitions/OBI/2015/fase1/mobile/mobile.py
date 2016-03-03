a = int(raw_input())
b = int(raw_input())
c = int(raw_input())
d = int(raw_input())

if a == b + c + d and b + c == d and b == c:
	print 'S'
else:
	print 'N'
