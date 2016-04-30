from time import time

t1 = time()

def binSearch(b, e, value, cont_pos):
    while b <= e:
	m = (b+e)/2
	if value == cont_pos*m: return m
	elif m*cont_pos < value: b += 1
	else: e -= 1
    return 0

s = raw_input().split("=")

n = int(s[1])
s = s[0]

cont_pos = 0
cont_neg = 0

for i in xrange(len(s)):
    if i == 0:
        if s[i] == '?': cont_pos += 1
    else:

        if s[i] == '?' and s[i-2] == '+': cont_pos += 1
        elif s[i] == '?' and s[i-2] == '-': cont_neg += 1

a = 0
b = 0

for i in xrange(1, n+1):
    res = binSearch(1, n, i*cont_neg + n, cont_pos)
    if res > 0 and res <= n:
	b = i
	a = res
	break

if a == 0 and b == 0: print 'Impossible'
else: 
    print 'Possible'
    for i in xrange(len(s)):
	    if s[i] == ' ': continue
	    if i == 0:
		if s[i] == '?': print a,    
	    else:
		if s[i] == '?' and s[i-2] == '+': print a,
		elif s[i] == '?' and s[i-2] == '-': print b,
		else: print s[i],
    print '=', n

t2 = time()
print t2 - t1
