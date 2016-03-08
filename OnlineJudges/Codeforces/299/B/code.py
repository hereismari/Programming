import math

s = raw_input()

n = 0
i = 1
for e in s:
	if e == '7':
		n += pow(2,len(s) - i)		
	i += 1

#print n
#print pow(2,len(s)) - 1
answer = pow(2,len(s)) -1 + n

print answer

