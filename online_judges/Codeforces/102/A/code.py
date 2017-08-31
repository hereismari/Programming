
global r1,r2,c1,c2,d1,d2

def valid(x,y,z,w):
	if x + y != r1:
		return False
	if z + w != r2:
		return False
	if x + w != d1:
		return False
	if y + z != d2:
		return False
	if x + z != c1:
		return False
	if y + w != c2:
		return False

	if x == y:
		return False
	if x == z:
		return False
	if x == w:
		return False
	if y == z:
		return False
	if y == w:
		return False
	if z == w:
		return False

	return True

r1,r2 = map(int,raw_input().split())
c1,c2 = map(int,raw_input().split())
d1,d2 = map(int,raw_input().split())

done = False
for x in range(1,10):
	if done:
		break
	for y in range(1,10):
		if done: break
		for z in range(1,10):
			if done: break
			for w in range(1,10):
				if(valid(x,y,z,w)):
					done = True
					print x,y
					print z,w
					break
if not done:
	print -1
