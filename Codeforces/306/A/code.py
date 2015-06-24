s = raw_input()

finish = False

for i in range(len(s)-1):
	if(s[i] + s[i+1] == "BA"):
		s2 = s[i+2::]
		if "AB" in s2:
			print "YES"
			finish = True
		break

if not finish:
	for i in range(len(s)-1):
		if(s[i] + s[i+1] == "AB"):
			s2 = s[i+2::]
			if "BA" in s2:
				print "YES"
				finish = True
			break

if not finish:
	print "NO"

