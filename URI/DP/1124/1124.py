import math
while True:
     
    l,c,r1,r2 = map(int,raw_input().split())
    if (l == 0 and c == 0 and r1 == 0 and r2 == 0):
         break
    
    if (2*r1 > l or 2*r1 > c or 2*r2 > l or 2*r2 > c):
	print "N"
    else:
	x = False
    	x1 = r1
	y1 = c - r1
	
	for i in range(1,4):
	   if (i == 1):
		x2 = r2
		y2 = r2
	   elif i == 2:
		x2 = l - r2
		y2 = r2
	   elif i == 3:
		x2 = l - r2
		y2 = c - r2
           if(math.sqrt(pow(x2-x1,2) + pow(y2-y1,2))>= r1 + r2):
		x = True 
        if x:
	  print "S"
	else:
	  print "N"
    
