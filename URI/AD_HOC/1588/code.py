k = int(raw_input())
 
def swap(struct,i,j):
    tmp = struct[i]
    struct[i] = struct[j]
    struct[j] = tmp

def sort(struct, comp): 
    print comp
    for i in range(len(struct)):
        for j in range(i+1,len(struct)):
			if(comp[struct[i]] < comp[struct[j]]):
				swap(struct,i,j)
 
for i in range(k):
 
    n,m = map(int,raw_input().split())
     
    s = []
    v = {}
    g = {}
    p = {}
    pos = {}

    for j in range(n):
        x = raw_input()
        s.append(x)
        v[x] = 0
        g[x] = 0
        p[x] = 0
        pos[x] = j
    for j in range(m):
        g1,t1,g2,t2 = raw_input().split()
        g[t1] += int(g1)
        g[t2] += int(g2)
         
        if(g1 > g2): 
            p[t1] += 3
            v[t1] += 1
        elif (g2 > g1): 
            p[t2] += 3
            v[t2] += 1
        else:
            p[t1] += 1
            p[t2] += 1
                    
	sort(s,p)
	sort(s,v)
	sort(s,g)
	sort(s,pos)

    for e in s:
        print e
