INF = 100000000000
ans = INF
x = 110000
adj = [[] for i in xrange(x)]
vis = [False] * x

def dfs(node):
    vis[node] = True
    if len(adj[node]) == 1: return 0

    global ans
    min_dist = INF
    for e in adj[node]:
        if not vis[e]:
            aux = dfs(e) + 1
            ans = min(ans, aux + min_dist)
            min_dist = min(min_dist, aux)

    return min_dist

n = int(raw_input())
for i in xrange(n-1):
    x, y = map(int, raw_input().split())
    adj[x].append(y)
    adj[y].append(x)

if n == 2: ans = 1
else:
    for e in xrange(1, n+1):
        if len(adj[e]) > 1:
            dfs(e)
            break

print ans
