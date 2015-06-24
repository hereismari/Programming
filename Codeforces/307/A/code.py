n = int(raw_input())

l = map(int,raw_input().split())

mapa = {}

for i in range(1,n+1):
	mapa[i] = l[i-1]

print mapa
