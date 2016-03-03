
s = raw_input()
t = raw_input()

p = ""
cont = 0
for i in xrange(len(s)):
	if s[i] != t[i]: cont += 1

if cont % 2 == 1: print "impossible"
else:
	cont = 0
	for i in xrange(len(s)):
		if s[i] == t[i] : p += s[i]
		
		elif cont % 2 == 0: 
			p += s[i]
			cont += 1
		else:
			p += t[i] 
			cont += 1	

	print p
