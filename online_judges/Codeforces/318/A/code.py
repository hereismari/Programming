n = int(raw_input())
a = map(int,raw_input().split())
value = a[0]
maiores = []
for e in a[1::]:
	if e >= value:
		maiores.append(e)	

ans = 0
while True and len(maiores) > 0:
	maiores.sort()
	max_value = maiores[len(maiores)-1]
	if(max_value < value): break
	ans += 1
	value += 1
	maiores[len(maiores)-1] = -1
	maiores.append(max_value -1)

print ans
