
soma = 0
while True:
	try:
		s = raw_input()
		if s == "caw caw": 
			print soma
			soma = 0
		else:
			for i in range(len(s)):
				if(s[i] == '*'):
					if(i == 0):
						soma += 4
					elif(i == 1):
						soma += 2
					else:
						soma += 1 
	except:
		break
