
while True:
	try:
		line = raw_input().split()
	except EOFError:
		break
	
	inValid = False
	outRange = False
	
	en1 = line[0]
	en2 = line[1]
	en3 = line[2]
	
	ip1 = en1.split('.')
	ip2 = en2.split('.')
	ip3 = en3.split('.')
	
	ip1 = map(int,ip1);
	ip2 = map(int,ip2);
	#print ip1,ip2,ip3
	
	if(len(ip3) != 4):
		inValid = True
	
	if(not inValid):
		ip3 = map(int,ip3);
		
		for i in range(4):
			if(ip3[i] < 0 or ip3[i] > 255):
				inValid = True
	
		for i in range(4):
			if(ip1[i] != ip2[i] and ip3[i] < ip2[i] and ip3[i] > ip1[i]):
				break
			if(ip3[i] < ip1[i] or ip3[i] > ip2[i]):
				outRange = True 
	
	if(inValid):
		print "InValid"
	elif(outRange):
		print "OutRange"
	else:
		print "InRange"
