n, k = map(int,raw_input().split())
valores = map(int,raw_input().split())
dias = raw_input().split()

aux = [0] * 101
soma = 0
for e in valores:
	aux[e] += 1
	soma += e

num_arvores_vivas = k
acumulador = 0
resposta = 0

for e in dias:
	if e == 'C':
		acumulador += 1
	else:
		acumulador -= 1
		if(acumulador < 0 and acumulador >= -100):
			num_arvores_vivas -= aux[abs(acumulador)]
			soma += acumulador * aux[abs(acumulador)] 
			aux[abs(acumulador)] = 0
	
	resposta += soma + num_arvores_vivas * acumulador
print resposta

