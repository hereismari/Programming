from sets import Set

set1 = Set([])

l = "qwertyuiopasdfghjklzxcvbnm"

s = raw_input()

for i in range(len(s)+1):
	for e in l:
		x = s[:i:] + e + s[i::]
		set1.add(x)

print len(set1)
