MAX = 1000000

n = int(raw_input())

l2 = {}

l = map(int,raw_input().split())
for e in l:
	l2[e] = 0
	l2[e-1] = 0

for e in l:
	l2[e]+=1

x = 0
y = 0
print l2
for i in l2.keys(): 
	print l2[i],i
	if l2[i] >= 4 and i > x and i > y:
		x = i
		y = i
	elif l2[i] >= 2 and i > x:
		y = x
		x = i
	elif l2[i] >= 2 and i > y:
		y = i 
	elif l2[i] >= 4 and i-1 > x and i-1 > y:
		x = i-1
		y = i-1
	elif l2[i] >= 2 and i-1 > x:
		y = x
		x = i-1
	elif l2[i] >= 2 and i-1 > y:
		y = i-1 
print x*y
