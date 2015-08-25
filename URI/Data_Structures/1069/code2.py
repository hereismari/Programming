n = int(raw_input())

for i in xrange(n):
    s = raw_input()
    fila = 0
    resposta = 0
    for e in s:
        if e == '<':
            fila += 1
        elif e == '>' and not fila == 0:
            fila -= 1
            resposta += 1
    print resposta

