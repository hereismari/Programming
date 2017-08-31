def printLista(l):
	for e in l:
		print e[1],
	print

n = int(raw_input())
lista = map(int, raw_input().split())
aux = []
for i in xrange(n):
	aux.append([lista[i],i+1])

cont = 0
for i in xrange(n):
	for j in xrange(i+1,n):
		if(aux[i][0] == aux[j][0]): cont += 1

if cont <= 1:
	print "NO"
else:
	print "YES"
	aux.sort()
	printLista(aux)
	listas_impressas = 1
	for i in xrange(n-1):
		if aux[i][0] == aux[i+1][0]:
			aux[i],aux[i+1] = aux[i+1],aux[i]
			printLista(aux)
			listas_impressas += 1
		if listas_impressas >= 3:
			break

