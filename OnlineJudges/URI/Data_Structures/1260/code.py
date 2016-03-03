n = int(raw_input())
i = 1
s = raw_input()
d = {}
cont = 0

while True:
	
	try: s = raw_input()
	except EOFError:
		for e in sorted(d):
			print "%s %.4f" % (e,(d[e]*100.0)/cont)
		i += 1
		d = {}
		cont = 0
		break

	if len(s.strip()) == 0:
		for e in sorted(d):
			print "%s %.4f" % (e,(d[e]*100.0)/cont)
		print
		i += 1
		d = {}
		cont = 0
		continue

	cont += 1

	if s in d: d[s] += 1
	else: d[s] = 1
