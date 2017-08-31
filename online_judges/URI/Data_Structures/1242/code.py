while True:

    try:
        s = raw_input()
    except:
        break

    bs = 0
    cf = 0

    ans = 0
    queue = []

    for i in xrange(len(s)):

        if len(queue) == 0: queue.append(s[i])
        else:
            if s[i] == 'F' and queue[-1] == 'C':
                ans += 1
                queue.pop()
            elif s[i] == 'C' and queue[-1] == 'F':
                ans += 1
                queue.pop()
            elif s[i] == 'B' and queue[-1] == 'S':
                ans += 1
                queue.pop()
            elif s[i] == 'S' and queue[-1] == 'B':
                ans += 1
                queue.pop()
            else:
                queue.append(s[i])

    print ans
