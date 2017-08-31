def maxAns(x,y):

    r = 9*x*x + y*y
    b = 2*x*x + 25*y*y
    c = -100*x + y*y*y

    if r > b and r > c: return "Rafael"
    if c > r and c > b: return "Carlos"
    if b > c and b > r: return "Beto"

n = int(raw_input())
for i in xrange(n):
    x,y = map(int,raw_input().split())
    print maxAns(x,y) + ' ganhou'
