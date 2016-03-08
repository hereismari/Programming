n = int(raw_input())
mapa1 = {}
mapa2 = {}
for e in range(n):
	b,c,e = raw_input().split()
	mapa1[b] = c
	mapa2[b] = e

x = '0'
answer = ""
while x != '1':
	answer += mapa1[x]
	x = mapa2[x]
print answer
