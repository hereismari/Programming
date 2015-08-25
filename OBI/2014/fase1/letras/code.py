c = raw_input()
s = raw_input().split()

ans = 0
for e in s:
    if c in e:
        ans += 1
print "%.1f" % ((ans/(len(s)*1.0)) * 100.0)
