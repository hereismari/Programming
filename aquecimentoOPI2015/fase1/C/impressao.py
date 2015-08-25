def swap(x,y):
	tmp = x
	x = y
	x = tmp

def percentual(x,y):
	if x < y: return 100.0
	return (y * 100.0)/x

while True:

	x1,y1,x2,y2 = map(int,raw_input().split())
	if x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0: break

#	if x1 > y1: swap(x1,y1)
#	if x2 > y2: swap(x2,y2)
	per1 = percentual(x1,x2)
	per2 = percentual(y1,y2)
	min1 = min(per1,per2)

	per3 = percentual(x1,y2)
	per4 = percentual(y1,x2)
	min2 = min(per3,per4)

	print str(int(max(min1,min2))) + "%"
