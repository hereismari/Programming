queries = int(raw_input())

pontuation = {'RG' : 2, 'GB' : 2, 'BR' : 2, 'RB': 1, 'BG': 1, 'GR' : 1}

while queries > 0:

    queries -= 1

    n = int(raw_input())

    ans = {'R' : 0, 'G': 0, 'B' : 0}
    for i in xrange(n):
        x, y = raw_input().split()
        ans[x] += pontuation[x+y]

    maximum = max(ans.values())
    cont = 0
    for e in ans:
        if ans[e] == maximum:
            cont += 1

    if cont == 3:
        print 'trempate'
    elif cont > 1:
        print 'empate'
    elif ans['R'] == maximum:
        print 'red'
    elif ans['G'] == maximum:
        print 'green'
    else:
        print 'blue'
