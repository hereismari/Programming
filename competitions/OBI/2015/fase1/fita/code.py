n = int(raw_input())
l = map(int,raw_input().split())

dist = -1
for i in xrange(n):
	if l[i] == 0:
		dist = 0
	elif dist != -1 and (dist < l[i] or l[i] == -1):
		l[i] = dist
	if dist != -1:
		dist += 1
	if dist > 9:
		dist = 9
dist = -1
for i in xrange(n-1,-1,-1):
	if l[i] == 0:
		dist = 0
	elif dist != -1 and (dist < l[i] or l[i] == -1):
		l[i] = dist
	if dist != -1:
		dist += 1
	if dist > 9:
		dist = 9
for e in l:
	print e,
print 
