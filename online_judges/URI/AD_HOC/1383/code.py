n = int(raw_input())

s = [1, 2, 3, 4, 5, 6, 7, 8, 9]

def check(a, b, m, s):

    cont = []
    for i in xrange(a, a+3):
        for j in xrange(b, b+3):
            cont.append(m[i][j])

    res = True
    for e in s: 
        if not e in cont: res = False

    return res

for k in xrange(n):

    mat = []
    for i in xrange(9):
        mat.append(map(int, raw_input().split()))


    flag = True
    for i in xrange(9):
        cont = []
        for j in xrange(9):
            cont.append(mat[i][j])

        for e in s: 
            if not e in cont: flag = False

    for i in xrange(9):
        cont = []
        for j in xrange(9):
            cont.append(mat[j][i])
        for e in s: 
            if not e in cont: flag = False
    
    for i in xrange(0, 9, 3):
        for j in xrange(0, 9, 3):
            if not check(i, j, mat, s): flag = False

    print "Instancia", k+1
    if flag: print "SIM"
    else: print "NAO"
    print
