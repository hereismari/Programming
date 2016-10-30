n, m = map(int, raw_input().split())

for i in xrange(1, 11):
    if (n * i) % 10 == 0 or (n * i) % 10 == m:
        print i
        break


