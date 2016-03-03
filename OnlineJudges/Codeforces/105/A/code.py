from sets import Set
values = [0]*4
for i in range(4):
	values[i] = int(raw_input())

d = int(raw_input())
s = Set()

for i in range(4):
	k = values[i]
	while values[i] < d + 1:
		s.add(values[i])
		values[i] += k
print len(s)

