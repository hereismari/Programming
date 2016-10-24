while True:

    n, m = map(int, raw_input().split())
    if n == 0 and m == 0: break

    coins = map(int, raw_input().split())

    dp = [0 for i in xrange(n+1)]
    dp[0] = 1

    for coin in coins:
        for value in xrange(n, 0, -1):
            if coin <= value:
                dp[value] += dp[value - coin]

    if dp[n] > 0:
        print 'sim'
    else:
        print 'nao'
