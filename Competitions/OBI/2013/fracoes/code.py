l = map(int,raw_input().split())

numerador = l[0]*l[3] + l[1]*l[2]
denominador = l[1]*l[3]

for i in range(2,101):
	while numerador % i == 0 and denominador % i == 0:
		numerador /= i
		denominador /= i

print numerador, denominador 

