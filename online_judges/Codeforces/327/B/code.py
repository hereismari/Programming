m = {}

def connect(b, x):
    for e in m:
        if m[e] == x:
            aux1 = e
        if m[e] == b:
            aux2 = e

    aux = m[aux1]
    m[aux1] = m[aux2]
    m[aux2] = aux
    
for e in 'qwertyuioplkjhgfdsazxcvbnm': m[e] = e

k, n = map(int, raw_input().split())
s = raw_input()

for i in xrange(n):
    x, y = raw_input().split()
    connect(x, y)

ans = ""
for e in s:
    ans += m[e]

print ans
