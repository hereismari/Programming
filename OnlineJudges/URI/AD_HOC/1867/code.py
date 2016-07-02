
def solve(s):

    if s < 10: return s
    else:
    
        res = 0
        while s > 0:
            res += s % 10
            s /= 10
        return solve(res)

while True:
    try:
        a, b = raw_input().split()
    except:
        break

    if a == '0' and b == '0': break
    
    n = 0
    for e in a: 
        n += (ord(e) - ord('0'))
    
    m = 0
    for e in b: m += (ord(e) - ord('0'))

    ans_n = solve(n)
    ans_m = solve(m)

    if ans_n > ans_m: print 1
    elif ans_n < ans_m: print 2
    else: print 0
