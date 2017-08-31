n , m = map(int,raw_input().split())
l = map(int,raw_input().split())

l.sort()

girls = min(l[n]/2.0,l[0])
boys = min(l[n], l[0]*2)
answer = girls * n + boys * n
print min(answer,m)
