n = int(raw_input())

mapa = {}
maior = 0

for i in range(n):
    x = raw_input()
    if not x in mapa:
        mapa[x] = 1
    else:
        mapa[x] += 1
    if mapa[x] > maior:
        maior = mapa[x]
        m = x

print m
