x = int(raw_input())
while x > 0:
    try:
        n,m = raw_input().split()
    except:
        break
    
    l_n = len(n)
    l_m = len(m)
    if l_m > l_n: print 'nao encaixa'
    elif n[l_n-l_m:] == m: print 'encaixa'
    else: print 'nao encaixa'
    x -= 1
