import math

n = int(raw_input())

cont = 0
for i in xrange(1,n):
	for j in xrange(i,n):
		soma_triangulo = i*i + j*j
		if(soma_triangulo > n*n): break
		r_soma_triangulo = int(math.sqrt(soma_triangulo))
		
		if(soma_triangulo <= n*n and r_soma_triangulo*r_soma_triangulo == soma_triangulo):
			cont += 1

print cont


