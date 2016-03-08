n = int(raw_input())
mapa = {}

answer = 1
for i in range(n):
	s = raw_input()
	if s in mapa:
		mapa[s] += 1
	else:
		mapa[s] = 1

for e in mapa:
	if mapa[e] > answer:
		answer = mapa[e]

print answer
