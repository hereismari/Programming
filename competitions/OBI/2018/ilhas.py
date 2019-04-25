import heapq

n, m = map(int, raw_input().split())

adj_list = [[] for _ in xrange(n+1)]
from heapq import *

INF = 1e9

def bfs(no):
    dist = [INF for _ in xrange(n+1)]
    q = []
    
    heappush(q, (0, no))
    dist[no] = 0
    
    while q:
        top_dist, top = heappop(q)
        for dist_v, v in adj_list[top]:
            if top_dist + dist_v < dist[v]:
                dist[v] = top_dist + dist_v
                heappush(q, (dist[v], v))
                
    return dist


for _ in xrange(m):
        a, b, p = map(int, raw_input().split())
        adj_list[a].append((p, b))
        adj_list[b].append((p, a))
  
s = int(raw_input())
dists = bfs(s)

max_value, min_value = None, None
for i in xrange(1, n+1):
    if i == s: continue
    if max_value is None or max_value < dists[i]:
        max_value = dists[i]
    
    if min_value is None or min_value > dists[i]:
        min_value = dists[i]
        
print(max_value - min_value)
