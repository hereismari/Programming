m = {}

c = 1
for i in xrange(3):
    for j in xrange(3):
        m[c] = (i, j)
        c += 1
m[0] = (3,1)

n = int(raw_input())
s = raw_input()

count1 = [0] * 4
count2 = [0] * 4

for e in s:
    count1[m[int(e)][0]] += 1
    count2[m[int(e)][1]] += 1

flag = count1[0] > 0 and count1[2] > 0 and count2[0] > 0 and count2[2] > 0
flag |= count1[3] > 0 and count1[0]

if flag: print "YES"
else: print "NO"
