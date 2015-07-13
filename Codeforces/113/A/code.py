s = ["lios","liala","etr","etra","initis","inites"]

input_string = raw_input().split()
answer = True
for e in input_string:
	flag = False
	for k in s:
		if e.endswith(k):
			flag = True
	if not flag: 
		answer = False
		break

if (answer): print "YES"
else: print "NO"
