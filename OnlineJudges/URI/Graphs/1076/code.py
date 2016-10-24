ans = 0

def dfs(graph, vis, node):

    global ans

    vis[node] = 1

    for v in graph[node]:
        if not vis[v]:
            ans += 1
            dfs(graph, vis, v)
    ans += 1
t = int(raw_input())

while t > 0:
    global ans
    ans = 0
    t -= 1

    n = int(raw_input())
    v, a = map(int, raw_input().split())
    graph = [[] for j in xrange(v + 2)]
    vis = [0 for i in xrange(v + 2)]

    for i in xrange(a):
        x, y = map(int, raw_input().split())
        graph[x].append(y)
        graph[y].append(x)

    dfs(graph, vis, n)
    print ans - 1
