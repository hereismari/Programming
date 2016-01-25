n, m = map(int, raw_input().split())

if n > m + 1 or m > 2*n + 2: print -1
else:

    ans = ''
    while m > n + 1 and n >= 1:
        ans += '110'
        m -= 2
        n -= 1

    if n == 0 and m <= 2: print ans + m * '1'
    elif n >= m:
        i = 0
        while m > 0:
            if i % 2 == 0: 
                ans += '0'
                n -= 1
            else:
                ans += '1'
                m -= 1
            i += 1
        for i in xrange(n): ans += '0'
        print ans
    else:
        i = 0
        while n > 0:
            if i % 2 == 0:
                ans += '1'
                m -= 1
            else:
                ans += '0'
                n -= 1
            i += 1
        for i in xrange(m): ans += '1'
        print ans
