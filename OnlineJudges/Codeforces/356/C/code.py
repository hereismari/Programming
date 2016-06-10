from sys import stdout

s = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
print len(s)
cont = 0
for i in xrange(len(s)):
    print s[i]
    stdout.flush()
    x = raw_input()
    if x == 'yes': cont += 1
    if cont >= 2: break
    stdout.flush()

if cont >= 2: print 'composite'
else: print 'prime'

stdout.flush()



