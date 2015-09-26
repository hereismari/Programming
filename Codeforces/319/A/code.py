n, x = map(int,raw_input().split())

ans = 0
for i in xrange(1, n+1):
	if x % i == 0:
		m = x/i
#		print m, i
		if m <= n: ans += 1
	else:
		continue

print ans
