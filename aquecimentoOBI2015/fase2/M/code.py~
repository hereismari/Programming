from Queue import Queue

def bfs(visitado, a):

    q = Queue()
    q.put((1,1)) # insert tupla (1,1) que eh a posicao inicial    
    visitado[1][1] = 1
    while not q.empty():
	top = q.get();
	i,j = top[0], top[1]	
	visitado[i][j] = 1
	if a[i-1][j] == 0 and visitado[i-1][j] == 0: q.put((i-1,j))
	if a[i+1][j] == 0 and visitado[i+1][j] == 0: q.put((i+1,j))
	if a[i][j-1] == 0 and visitado[i][j-1] == 0: q.put((i,j-1))
	if a[i][j+1] == 0 and visitado[i][j+1] == 0: q.put((i,j+1))

    return visitado[5][5]

SIZE = 5
n = int(raw_input())
for x in xrange(n):
    buffer_ = raw_input()
    a = [[1 for i in xrange(SIZE + 2)]] #list comprehension
    for i in xrange(SIZE):
        a.append([1] + map(int,raw_input().split()) + [1])
    #motivo de ser 1, nao tem que se preocupar de visitar posicoes erradas
    #motivo para o SIZE + 2, nao ter que verificar se eh a pos eh == 0 ou pos == 4
    a.append([1 for i in xrange(SIZE + 2)])
    visitado = [[0 for i in xrange(SIZE + 2)] for i in xrange(SIZE + 2)] #list comprehension

    if bfs(visitado, a):
        print ("COPS\n")
    else:
        print ("ROBBERS\n")
