def solve(x, n):
    
    cont = 0

    while x > n:
        if x % 2 == 0: x /= 2
        else: x += 1
        cont += 1

    return cont + (n-x)

n, m = map(int, raw_input().split())
print solve(m, n)
