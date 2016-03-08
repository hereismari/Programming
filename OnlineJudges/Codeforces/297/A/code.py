
n = int(raw_input())
s = raw_input()
cont = 0
v = []
for i in range(35):
	v.append(0)
for e in s:
	if e.isupper():
		if (v[ord(e)- ord('A')] > 0 ):
			v[ord(e) - ord('A')] -= 1
		else:
			cont += 1;
	else:
		v[ord(e) - 97] += 1;

print cont
