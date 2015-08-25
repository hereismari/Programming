while True:
    try:
        n = int(raw_input())
    except:
        break

    posicao_1 = 0
    posicao_2 = n-1

    m = []
    for i in xrange(n):
        m.append([])
        for j in xrange(n):
            m[i].append(3)

    for i in xrange(n):
        for j in xrange(n):
            if j == posicao_1: m[i][j] = 1
            if j == posicao_2: m[i][j] = 2

        posicao_1 += 1
        posicao_2 -= 1

    for e in m:
        ans = ""
        for x in e:
            ans += str(x)
        print ans
