import math
pi  = 3.141592654
while True:
	try: ang, dist, h = map(float, raw_input().split())
	except: break
	ang = (ang * pi) / 180.0
	print '%.2f' % (((math.tan(ang)*dist) + h)*5.0)
