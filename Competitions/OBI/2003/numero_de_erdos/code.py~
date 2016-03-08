from Queue import Queue

sobrenome = {}
mapa =  {}
dist = []
ERDOS = "P. Erdos"
NUM_ERDOS = 1
MAX = 110
INF = 100000

def bfs(dist, adj):

    visited = [False]*MAX
    q = Queue()
    d = Queue()
    q.put(NUM_ERDOS)
    d.put(0)
    visited[NUM_ERDOS] = True

    while(not q.empty()):
        top = q.get()
        distancia = d.get()
        for i in xrange(MAX):
            if adj[top][i] == 1 and not visited[i]:
                q.put(i)
                d.put(distancia + 1)
                visited[i] = True
                dist[i] = distancia + 1
teste = 1
while True:
    cont = 2
    adj = [[ 0 for i in xrange(MAX)] for i in xrange(MAX)]
    mapa = {}
    nome = {}
    sobrenome = {}
    dist = [INF]*MAX
    a = []

    mapa[ERDOS] = NUM_ERDOS

    n = int(raw_input())
    if n == 0: break
    for i in xrange(n):
        s = raw_input().split(', ')
        s[-1] = s[-1][:len(s[-1])-1:]
        for e in s:
            if e != ERDOS and not e in mapa:
                mapa[e] = cont
                a.append(cont)
                nome[cont] = e
                sobrenome[cont] = e[3::]
                cont += 1
        for i in xrange(len(s)):
            for j in xrange(i+1,len(s)):
                adj[mapa[s[j]]][mapa[s[i]]] = 1
                adj[mapa[s[i]]][mapa[s[j]]] = 1

    for i in xrange(len(a)):
        for j in xrange(len(a)-i-1):
            if(sobrenome[a[j+1]] == sobrenome[a[j]]):
                if(nome[a[j+1]] < nome[a[j]]):
                    a[j+1],a[j] = a[j], a[j+1]
            elif(sobrenome[a[j+1]] < sobrenome[a[j]]):
                    a[j+1], a[j] = a[j], a[j+1]
    bfs(dist, adj)

    print "Teste " + str(teste)
    teste += 1

    for i in xrange(len(a)):
        if dist[a[i]] == INF:
            print nome[a[i]] + ': infinito'
        else:
            print nome[a[i]] + ': ' + str(dist[a[i]])
    print
