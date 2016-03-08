n = int(raw_input())

i = 1
cont = 1
answer = 0
while n/i >= 10:
	 answer += 9*i*cont
	 i *= 10
	 cont += 1

answer += (n-i + 1)*(cont)
if n >= 10:
	print answer
else:
	print n

