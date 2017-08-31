n,m = map(int,raw_input().split())
l = map(int,raw_input().split())

resposta = 0
casa = 1

for e in l:
	if e >= casa:
		resposta += e - casa
	else:
		resposta += n - casa + e  
	casa = e

print resposta
