
def gcd(x, y):
	return x if y == 0 else gcd(y, x % y)

t1, t2, n = map(int, raw_input().split())

interval = (t2 - t1) * 60;

b = interval * interval
a = b - (interval-n)*(interval-n)

print "%d/%d" % (a/gcd(a,b), b/gcd(a,b))
