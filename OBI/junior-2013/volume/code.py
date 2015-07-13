n, m = map(int,raw_input().split())
l = map(int,raw_input().split())

for e in l:
	n += e
	if n < 0: n = 0
	if n > 100 : n = 100

print n



