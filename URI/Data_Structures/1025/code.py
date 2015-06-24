

cont = 1

while True:

	n,m = map(int,raw_input().split())
	if(n == 0): break
	lista = [0]*10001
	lista2 = [0]*10001
	
	for i in range(n):
		x = int(raw_input())
		lista[x] += 1
		lista2[x] += 1

	for i in range(1,len(lista)):
		lista[i] += lista[i-1];
	
	print "CASE#" + " " + str(cont) + ":"
	for i in range(m):
		x = int(raw_input())
		if(lista2[x] != 0):
			print str(x) + " found at " + str(lista[x] - lista2[x] + 1)
		else: print str(x) + " not found"
	
	cont += 1
