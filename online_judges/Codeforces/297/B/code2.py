
s = raw_input()
length = len(s)

n = int(raw_input())
l = map(int,raw_input().split())

#print mapa
x = s[::]
for e in l:
	if e == 1:
		x = x[::-1]
	else:
		#print x[:e-1:]
		#print x[length - e :e-2: -1]
		#print x[length -e + 1::]
		x = x[:e-1:] + x[length - e :e-2: -1] + x[length -e + 1::]
	
print x
