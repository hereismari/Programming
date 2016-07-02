def bin_search(x, lista):
	meio = (len(lista))/2
	inicio = 0
	fim = len(lista)
	while inicio < fim:
		if lista[meio] < x: inicio = meio + 1
		elif lista[meio] > x: fim = meio
		else: return meio
		meio = (inicio + fim) / 2

	return fim

n = int(raw_input())
a = map(int,raw_input().split())

m = int(raw_input())
q = map(int,raw_input().split())

aux = []
soma_ac = 0

for e in a:
	soma_ac += e
	aux.append(soma_ac)

for e in q:
    print bin_search(e,aux) + 1
