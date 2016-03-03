from Queue import Queue

def bfs(x,visited):

    visited[x] = True
    q = Queue()
    q.put(x)
  
    while not q.empty():
        top = q.get()
        for e in adj[top]:
            if not visited[e]:
                visited[e] = True
                q.put(e)

t = int(raw_input())
for i in xrange(t):

    n = int(raw_input())
    m = int(raw_input())
    adj = []
    visited = [False]*(n+1)
    for j in xrange(n+1):
        adj.append([])

    for j in xrange(m):
        a,b = map(int,raw_input().split())
        adj[a].append(b)
        adj[b].append(a)

    print "Caso #" + str(i+1) + ':',
    resposta = 0
    for j in xrange(1,n+1):
        if not visited[j]:
            bfs(j,visited)
            resposta += 1

    if resposta == 1:
	print "a promessa foi cumprida"
    else:
	print "ainda falta(m) " + str(resposta-1) + " estrada(s)"
