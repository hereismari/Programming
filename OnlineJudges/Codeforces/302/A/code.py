n = int(raw_input())
s = raw_input()

answer = []
mapa = {}

x = 'abcdefghijklmnopqrstuvxzyw'

for e in x:
	mapa[e] = 0

if n == 1:
	print "YES"
	print s
elif n > len(s):
	print "NO"
	
else:

	cont = 0
	for i in range(len(s)):
		if mapa[s[i]] == 0:
			cont += 1
			answer.append(i)
			mapa[s[i]] += 1

	if cont >= n:
		print "YES"
		cont = 0
		i = 0
		while i < len(answer)-1:
			cont += 1
			print s[answer[i]:answer[i+1]:]
			i += 1
			if(cont == n-1): break
		print s[answer[i]:len(s):]

	else: print "NO"
