inp = raw_input()
i = 0
if '.' in inp :n, m = inp.split('.')
else:
	n = inp
	m = ""

s2 = ""
s1 = ""
if len(m) == 0: s2 = "00"
elif len(m) == 1: s2 = m + "0"
else: s2 = m[0] + m[1]

if n[0] == '-':
	n = n[1::]
	s1 += "("

s1 += "$"
for i in range(len(n)):
	s1 += n[i]
	if (len(n) - i -1) % 3 == 0  and i != len(n) - 1:
		s1 += ','

if inp[0] == '-': s2 += ')'

print s1 + '.' + s2

