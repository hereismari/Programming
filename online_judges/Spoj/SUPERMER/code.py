teste = 1
while True:
   
    n = int(raw_input())
    if n == 0: break
    x = []
    y = []
    for i in xrange(n):
        a,b = map(int,raw_input().split())
        x.append(a)
        y.append(b)
    x.sort()
    y.sort()
    print "Teste " + str(teste)
    print x[n/2], y[n/2]
    teste += 1