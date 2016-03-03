n = int(raw_input())
quadrado = []
for i in xrange(n):
    quadrado.append(map(int,raw_input().split()))

soma_magica = sorted([sum(quadrado[0]), sum(quadrado[1]), sum(quadrado[2])])[1]

for i in xrange(n):
    if sum(quadrado[i]) != soma_magica:
	linha_errada = i
for j in xrange(n):
    if sum([quadrado[i][j] for i in xrange(n)])  != soma_magica:
	coluna_errada = j

valor_errado = quadrado[linha_errada][coluna_errada]
print valor_errado + (soma_magica - sum(quadrado[linha_errada])), valor_errado
