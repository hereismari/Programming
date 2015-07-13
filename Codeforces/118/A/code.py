s1 = raw_input()
s2 = raw_input()

flag1 = False
flag2 = False
a = 0
b = 0

m1 = {}
m2 = {}

for e in s1:
	if not e in m1:
		m1[e] = 1
	else:
		m1[e] += 1

for e in s2:
	if not e in m2:
		m2[e] = 1
	else:
		m2[e] += 1

for e in m1:
	if m1[e] > 1 and(e in m2 and  m2[e] > 1): flag2 = True
cont = 0
for i in range(min(len(s1),len(s2))):
	if(s1[i] != s2[i] and not flag1):
		a = i
		b = i
		cont += 1
		flag1 = True
	elif(s1[i] != s2[i] and flag1):
		cont += 1
		b = i
if(s1[a] == s2[b] and s2[a] == s1[b] and len(s1) == len(s2) and cont == 2):
	print "YES"
elif(len(s1) == len(s2) and flag2 and not flag1):
	print "YES"
else:
	print "NO"
