
def zera():
	for e in ' QWERTYUIOPASDFGHJKLZXCVBNM':
		m[e] = 0

m = {}
while True:
	s = raw_input()
	if s == "FIM": break
	zera()
	for e in s:
		if e == ' ': continue
		m[e] += 1
	flag = False
	for e in m:
		if m[e] >= 2:
			flag = True
	if not flag:
		print s
