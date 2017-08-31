
from Queue import Queue

INF = 1000*1100
MAX = 1010

global flag1, flag2, flag3
flag1 = False
flag2 = False
flag3 = False

dist = []
for i in xrange(4):
    dist.append([])
    for j in xrange(MAX):
        dist[i].append([])
        for k in xrange(MAX):
            dist[i][j].append(INF)

n, m = map(int, raw_input().split())

def valid(i, x,y,x1,y1): 
    flag = x >= 0 and x < n and y >= 0 and y < m and graph[x][y] != '#' and dist[i][x1][y1] + 1 <= dist[i][x][y]
    return flag

def setDist(i):
    
    q = Queue()
    global flag1, flag2, flag3
    for k in xrange(n):
        for j in xrange(m):
            if graph[k][j] == str(i):
                q.put((k,j))
                dist[i][k][j] = 0

    while not q.empty():

        top = q.get()
        x = top[0]
        y = top[1]

        for e in [[0,-1], [0,1], [-1,0], [1,0]]:

            if flag1 and flag2 and flag3: return

            x1 = x + e[0]
            y1 = y + e[1]

            if valid(i, x1, y1, x, y):
                if graph[x1][y1] == '.':
                    dist[i][x1][y1] = dist[i][x][y] + 1
                    q.put((x1, y1))
                if i == 1 and graph[x][y] == '1' and graph[x1][y1] == '2': flag1 = True
                if i == 1 and graph[x][y] == '1' and graph[x1][y1] == '3': flag2 = True
                if i == 2 and graph[x][y] == '2' and graph[x1][y1] == '3': flag3 = True

graph = []

for i in xrange(n):
    graph.append(raw_input())

for i in xrange(1,4):
    setDist(i)

ans = INF
for i in xrange(n):
    for j in xrange(m):
        if graph[i][j] == '.':
#            print i,j, dist[1][i][j] + dist[2][i][j] + dist[3][i][j]
            ans = min(ans, dist[1][i][j] + dist[2][i][j] + dist[3][i][j] - 2)

if (flag1 and flag2) or (flag1 and flag3) or (flag2 and flag3): print 0
elif ans == INF: print -1
else: print ans 

