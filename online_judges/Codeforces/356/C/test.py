from sets import Set

def primes():

    p = []
    for i in xrange(2, 101):
        
        cont = 0
        for j in xrange(2, i+1):
            if i % j == 0:
                cont += 1
        if cont == 1: p.append(i)
    return p

def div(n):
    x = []
    for i in xrange(2, 101):
        if i % n == 0:
            x.append(i)
    return Set(x)

print primes()

k = int(raw_input())
asked = []

