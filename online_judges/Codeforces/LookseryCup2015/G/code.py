n = int(raw_input())
l = map(int,raw_input().split())

for i in xrange(len(l)):
	l[i] += i

l.sort()
flag = True
for i in xrange(len(l)-1):
	if(l[i] == l[i+1]):
		flag = False
		break

if not flag:
	print ":("
else:
	for i in xrange(len(l)):
		print l[i] - i,
