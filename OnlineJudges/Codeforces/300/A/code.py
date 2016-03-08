s = raw_input()
k = "CODEFORCES"
x = ""

answer = False
i = 0
if(len(s) >= len(k)):
	while i < len(k) and s[i] == k[i]: i += 1
	if i >= len(k): answer = True

if(len(s) >= len(k)):
	if not answer:
		while i < len(k) and s[len(s)-(len(k) -i)] == k[i]: i += 1
	if i >= len(k): answer = True

if len(s) < len(k): print "NO"
elif answer: print "YES"
else: print "NO"
