s = raw_input()
n = len(s)
ans = 0
m = {}

for i in range(n):
	aux = 0;
	for j in m.keys():
		aux = (m[j] if (j <= s[i] and m[j] > aux) else aux)
	m[s[i]] = aux + 1
	ans = max(ans,m[s[i]])

print ans
