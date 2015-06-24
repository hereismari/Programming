
def gera_subconjuntos(palavra):

	if(len(palavra) == 0): return
	print palavra
	subconjuntos.add(palavra)
	for i in range(len(palavra)):
	    if(palavra[:i] + palavra[i+1:] not in subconjuntos):
		    gera_subconjuntos(palavra[:i] + palavra[i+1:])

while True:
	
	try:
		s = raw_input()
	except:
		break

	subconjuntos = set()
	gera_subconjuntos(s)
	lista = list(subconjuntos)
	lista.sort()
	for e in lista:
		print e	
	print 

