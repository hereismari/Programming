MAX = 1000
memoria = [-1] * MAX

def fib(n):
    if memoria[n] == -1:
        if n <= 1:
            memoria[n] = n
        else:
            memoria[n] = fib(n - 1) + fib(n - 2)

    return memoria[n]


# Tests
assert fib(0) == 0
assert fib(1) == 1
assert fib(6) == 8
assert fib(9) == 34
