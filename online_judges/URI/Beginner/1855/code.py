def valid(x,y,n,m): return x >= 0 and y >= 0 and x < m and y < n

def can(mat, x, y, dire):
	#print mat[x][y], valid(x,y,n,m), pos[x][y]
	#print x,y
	if (not valid(x,y,n,m)) or (pos[x][y] and (mat[x][y] in '>v^<')):  return False	
	if mat[x][y] == '*': return True
	pos[x][y] = True
	if mat[x][y] == '>': return can(mat, x, y+1, '>')
	if mat[x][y] == '<': return can(mat, x, y-1, '<')
	if mat[x][y] == '^': return can(mat, x-1, y, '^')
	if mat[x][y] == 'v': return can(mat, x+1, y, 'v')

	if dire == '>': return can(mat, x, y+1, '>')
	if dire == '<': return can(mat, x, y-1, '<')
	if dire == '^': return can(mat, x-1, y, '^')
	if dire == 'v': return can(mat, x+1, y, 'v')

	return False
	
n = int(raw_input())
m = int(raw_input())

mat = []
pos = [[False for i in xrange(n)] for i in xrange(m)]

for i in xrange(m):
	mat.append(raw_input())
if can(mat, 0, 0, '.'):
	print '*'
else:
	print '!'
