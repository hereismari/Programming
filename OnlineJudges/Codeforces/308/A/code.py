n = int(raw_input())

m = []
for i in range(100):
	m.append([])
	for j in range(100):
		m[i].append(0)
for i in range(n):
	x1,y1,x2,y2 = map(int,raw_input().split())
	for j in range(x1-1,x2):
		for k in range(y1 -1, y2):
			m[j][k] += 1

answer = 0
for i in range(100):
	for j in range(100):
		answer += m[i][j]
print answer
