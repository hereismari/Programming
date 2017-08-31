n = int(raw_input())

for e in range(n):
	s = raw_input()
	print s[len(s)/2-1::-1] + s[:len(s)/2-1:-1]
	
