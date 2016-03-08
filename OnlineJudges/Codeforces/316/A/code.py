n,m = map(int,raw_input().split())

counter = [0] * (n+10)
for i in xrange(m):
    index = 0
    l = map(int,raw_input().split())
    for j in xrange(n):
        if l[j] > l[0]:
            index = j
    counter[index] += 1

index = 0
for i in xrange(len(counter)):
    if counter[i] > counter[index]:
        index = i

print index + 1
        
