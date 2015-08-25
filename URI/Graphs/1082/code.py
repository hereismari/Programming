from Queue import Queue

def bfs(x,visited,ref_int_char):

    visited[x] = True
    q = Queue()
    q.put(x)
    s = []
    s.append(ref_int_char[x])
    while not q.empty():
        top = q.get()
        for e in adj[top]:
            if not visited[e]:
                visited[e] = True
                q.put(e)
                s.append(ref_int_char[e])

    s.sort()
    resposta = ""
    for e in s:
        resposta += (e + ',')
    print resposta

ref_char_int = {}
ref_int_char = {}
s = "abcdefghijklmnopqrstuvwxyz"
for i in xrange(26):
    ref_char_int[s[i]] = i
    ref_int_char[i] = s[i]

t = int(raw_input())
for i in xrange(t):

    n,m = map(int,raw_input().split())
    adj = []
    visited = [False]*n
    for j in xrange(n):
        adj.append([])

    for j in xrange(m):
        a,b = raw_input().split()
        adj[ref_char_int[a]].append(ref_char_int[b])
        adj[ref_char_int[b]].append(ref_char_int[a])

    print "Case #" + str(i+1) + ':'
    resposta = 0
    for j in xrange(n):
        if not visited[j]:
            bfs(j,visited,ref_int_char)
            resposta += 1

    print str(resposta) + " connected components"
    print
