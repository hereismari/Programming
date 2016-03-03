n = int(raw_input())

mat = []
for i in xrange(n):
    mat.append(map(int,raw_input().split()))

mapa = {}
cont = 0
for i in xrange(2*n):
    m,k = map(int,raw_input().split())
    if mat[m-1][k-1] not in mapa:
        mapa[mat[m-1][k-1]] = 1
        cont += 1

print cont
