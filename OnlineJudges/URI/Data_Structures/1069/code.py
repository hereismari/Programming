from Queue import LifoQueue

n = int(raw_input())

for i in xrange(n):
    s = raw_input()

    fila = LifoQueue()
    resposta = 0
    for e in s:
        if e == '<':
            fila.put(1)
        elif e == '>' and not fila.empty():
            fila.get()
            resposta += 1
    print resposta

