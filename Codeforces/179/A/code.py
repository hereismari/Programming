n = int(raw_input())
l = map(int,raw_input().split())

values = {}

for e in l:
	if e not in values:
		values[e] = 1
	else:
		values[e] += 1

middle = n/2
if(n % 2 == 1): middle += 1

possible = True
for k,v in values.iteritems():
	if v > middle:
		possible = False

if possible: print "YES"
else : print "NO"
