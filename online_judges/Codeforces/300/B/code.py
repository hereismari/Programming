s = raw_input()
MAX = 100
answer = [0]*MAX
j = 1

for e in s[::-1]:
	for i in range(int(e)):
		answer[i] += j
	j *= 10

i = 0
cont = 0
while answer[i] != 0: 
	cont += 1
	i += 1

print cont
for i in range(cont):
	print answer[i],
print
