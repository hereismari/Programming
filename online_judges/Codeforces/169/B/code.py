value = {}
answer = ""

def setUp():
	answer = ""
	aux = "qwertyuioplkjhgfdsazxcvbnm"
	for e in aux:
		value[e] = 0

def query(s):
	for e in s:
		value[e] += 1

def isPalindrome():
	cont = 0
	for key in value:
		if value[key] % 2 == 1:
			cont += 1
	return (cont <= 1)

def answer():
	cont = 0
	while(not isPalindrome()):
		remove = False
		for key in value:
			if value[key] % 2 == 0 and value[key] != 0:
				value[key] -= 1
				remove = True
				break

		if not remove:
			for key in value:
				if value[key] != 0:
					value[key] -= 1
					break

		cont += 1

	if(cont % 2 == 0):
		return "First"
	else:
		return "Second"

s = raw_input()

setUp()
query(s)

print answer()

