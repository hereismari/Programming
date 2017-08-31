MAX = 201
global B
global A
global n,m
B = [[0 for i in xrange(MAX)] for i in xrange(MAX)]
A = [[0 for i in xrange(MAX)] for i in xrange(MAX)]

def linhaEColuna(i,j):

	for k in xrange(n):
		if B[k][j] == 0: return False
	for k in xrange(m):
		if B[i][k] == 0: return False
	
	return True

def linhaOuColuna(i,j):
	
	aux1 = aux2 = 1
	for k in xrange(n):
		if B[k][j] == 0: aux1 = 0
	for k in xrange(m):
		if B[i][k] == 0: aux2 = 0

	return aux1 + aux2;

n,m = map(int,raw_input().split())
for i in xrange(n):
	B[i] = map(int,raw_input().split())

flag = True
flag2 = True
cont = 0
for i in xrange(n):
	for j in xrange(m):
		if B[i][j] == 1 and linhaEColuna(i,j):
			A[i][j] = 1
			cont += 1
		if B[i][j] == 1 and linhaOuColuna(i,j) == 0:
			flag = False
		if B[i][j] == 1:
			flag2 = False
if flag and (cont > 0 or flag2):
	print "YES"
	for i in xrange(n):
		for j in xrange(m):
			print A[i][j],
		print
else:
	print "NO"	


