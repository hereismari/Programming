from Queue import Queue

global cycle

def bfs(x,color):

    color[x] = "GRAY"
    q = Queue()
    q.put(x)
    global cycle

    while not q.empty():
        top = q.get()
        for e in adj[top]:
            if color[e] == "WHITE":
                color[e] = "GRAY"
                q.put(e)
	    elif color[e] == "GRAY":
		cycle = True


t = int(raw_input())
for i in xrange(t):

    adj = []
    cycle = False
    n, m = map(int,raw_input().split())

    for i in xrange(n+1):adj.append([])
    color = ["WHITE"]*(n+1)

    for i in xrange(m):
        x,y = map(int,raw_input().split())
        adj[x].append(y)

    for i in xrange(1,n+1):
        if color[i] == "WHITE":
            bfs(i,color)
            if cycle: break
    if cycle:
        print "SIM"
    else:
        print "NAO"
