while True:

    n = int(raw_input())
    if n == 0: break

    ans = 0
    for i in xrange(0,n):
        val = n*n - 2*n*i + i*i
        ans += val

    print ans
