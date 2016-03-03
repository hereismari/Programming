s = raw_input()
num = [1]*7
finish = False

if len(s) >= 3:
	for i in range(len(s)):
		if finish: break
		for j in range(i+1,len(s)):
			if finish: break
			for k in range(j+1,len(s)):
				if finish: break
				num[0] = int(s[i])
				num[1] = int(s[j])
				num[2] = int(s[k])
				num[3] = int(s[i] + s[j])
				num[4] = int(s[i] + s[j] + s[k])
				num[5] = int(s[i] + s[k])
				num[6] = int(s[j] + s[k])
				for e in num:
					if e % 8 == 0:
						print "YES"
						print e
						finish = True
						break
elif len(s) == 1:
	if int(s) % 8 == 0:
		print "YES"
		print s
		finish = True

else:
	
	if int(s) % 8 == 0:
		print "YES"
		print s
		finish = True
	elif int(s[0]) % 8 == 0:
		print "YES"
		print s[0]
		finish = True
	elif int(s[1]) % 8 == 0:
		print "YES"
		print s[1]
		finish = True

if not finish:
	print "NO"
	
