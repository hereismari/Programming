n = int(raw_input())

ans = 0
while n >= 1:
	ans += n % 2
	n /= 2

print ans
