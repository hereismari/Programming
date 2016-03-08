def answer(n):
	cont = 1
	mod2 = 1
	mod1 = 10 % n
	while ((mod1*mod2) % n) != 0:
		mod2 = ((mod1*mod2) % n) + 1
		cont += 1
	return cont

while True:

	try:
		input = int(raw_input())
		print answer(input)
	except EOFError:
		break
