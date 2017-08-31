def solve(x):
    print 'I hate' if x % 2 == 0 else 'I love',

n = int(raw_input())

counter = 0

for i in xrange(n-1):
    solve(counter)
    print 'that',
    counter += 1

solve(counter)
print 'it'
