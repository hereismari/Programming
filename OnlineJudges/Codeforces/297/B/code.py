s = raw_input()

mapa1 = {}
mapa2 = {}
length= len(s)

for i in range(length):
	mapa1[i+1] = 0
	mapa2[i+1] = s[i]

n = int(raw_input())
l = map(int,raw_input().split())

for e in l:
	while e  < length - e +1:
		mapa1[e] += 1
		mapa1[length - e +1] += 1
		e += 1

#print mapa1

x = ""
for i in range(length/2):
	if(mapa1[i + 1] % 2 != 0):
		tmp = mapa2[i+1]
		mapa2[i+1] = mapa2[length - (i+1) + 1]
		mapa2[length - (i+1) + 1] = tmp
	
for i in range(length):
	x += mapa2[i+1]
	
print x
