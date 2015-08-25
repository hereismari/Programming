from Queue import Queue

def bfs(x, y):

    visited = [False]*(y+1+500000)
    visited[x] = True
    q = Queue()
    q.put([x,0])
  
    while not q.empty():
        top = q.get()
	#print top
	plus_one = top[0] + 1
	inverse = int(str(top[0])[::-1])        
	if plus_one == y or inverse == y:
	   return top[1] + 1
	if not visited[plus_one]:
           visited[plus_one] = True
           q.put([plus_one,top[1] + 1])
	if not visited[inverse]:
           visited[inverse] = True
           q.put([inverse,top[1] + 1])

t = int(raw_input())
for i in xrange(t):

    n, m = map(int,raw_input().split())	
    print str(bfs(n,m))
