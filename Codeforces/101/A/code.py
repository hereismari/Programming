s1 = raw_input()
s2 = raw_input()
s3 = raw_input()
flag = True
m1 = {}
for e in s1:
	if not e in m1:
		m1[e] = 1
	else:
		m1[e] += 1

for e in s2:
	if not e in m1:
		m1[e] = 1
	else:
		m1[e] += 1

m2 = {}
for e in s3:
	if not e in m2:
		m2[e] = 1
	else:
		m2[e] += 1

for e in m1:
	if not e in m2 or m1[e] != m2[e]:
		flag = False
		break

if(flag): print "YES"
else: print "NO"
