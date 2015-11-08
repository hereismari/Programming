m = []
for i in xrange(8):
    m.append(raw_input())

def calculateUp(i, j):

    ans = 0
    for k in xrange(i-1,-1,-1):
        if m[k][j] == 'B': return 10000000000
        else: ans += 1
    return ans

def calculateDown(i, j):

    ans = 0
    for k in xrange(i+1,8):
        if m[k][j] == 'W': return 10000000000
        else: ans += 1
    return ans

w = 10000000
b = 10000000

for i in xrange(8):
    for j in xrange(8):
        if m[i][j] == 'W':
            w = min(w, calculateUp(i, j))
        elif m[i][j] == 'B':
            b = min(b, calculateDown(i, j))
if w <= b: print 'A'
else : print 'B'
