while True:
    try:
        n = int(raw_input())
    except:
        break
    lista = []
    for i in xrange(n):
        a,b = map(int,raw_input().split())
        for i in xrange(a,b+1):
            lista.append(i)
    x = int(raw_input())
    inicio = fim = -1
    lista.sort()
    for i in xrange(len(lista)):
        if lista[i] == x and inicio == -1:
            inicio = i
        elif lista[i] != x and inicio != -1:
            fim = i
            break
    if inicio == -1:
        print str(x) + " not found"
    else:
        print str(x) + " found from " + str(inicio) + " to " + str(fim-1)

