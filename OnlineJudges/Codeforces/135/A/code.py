n = int(raw_input())
s = raw_input()

m = {}

for e in s:
	if not e in m:
		m[e] = 1
	else:
		m[e] += 1

possible = True
for e in s:
	if m[e] % n != 0: possible = False

ans = ""
if not possible: print -1
else:
	while len(ans) != len(s):
		for e in m:
			for i in range(m[e]/n): ans += e
	print ans
		
	
