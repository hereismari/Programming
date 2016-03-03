n = int(raw_input())

ciel = 0
jiro = 0

maxValues = []

for x in xrange(n):
	l = map(int,raw_input().split())
	if (l[0] % 2 == 0):
		for i in xrange(0,(l[0])/2):
			ciel += l[1 + i]
			jiro += l[l[0]/2 + i + 1]
	else:
		for i in xrange(0,((l[0])/2)):
			ciel += l[1 + i]
			jiro += l[(l[0])/2 + i + 2]

		maxValues.append(l[l[0]/2 + 1])

maxValues.sort()
k = 0
if(len(maxValues) % 2 == 0):
	k = 1
for i in range(len(maxValues)-1,-1,-1):
	if i % 2 == k:
		ciel += maxValues[i]
	else:
		jiro += maxValues[i]

print ciel, jiro
