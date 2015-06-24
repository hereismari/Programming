values = map(int,raw_input().split())
h,l = map(int,raw_input().split())

answer = False

for i in range(3):
	for j in range(3):
		if(i != j and values[i] <= h and values[j] <= l):
			answer = True

if (answer): print 'S'
else: print 'N'

