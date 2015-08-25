n = int(raw_input())

min_x,min_y = map(int,raw_input().split())
max_x = min_x
max_y = min_y

for i in xrange(n-1):
    x,y = map(int,raw_input().split())
    min_x = min(x,min_x)
    min_y = min(y,min_y)
    max_x = max(x,max_x)
    max_y = max(y,max_y)

lado = max(abs(max_x - min_x),abs(max_y - min_y))

print lado * lado
