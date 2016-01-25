l, r, k = map(int, raw_input().split())

v = 1
cont = 0

while v <= r:
    if v >= l and v <= r:
        print v,
        cont += 1
    v *= k


if cont == 0: print -1
else: print ""
    
