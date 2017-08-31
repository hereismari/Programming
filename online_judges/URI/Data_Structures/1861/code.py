ans = {}
dont_print = {}

while True:
	try:
		killer, dead = raw_input().split()
	except:
		break

	if killer in ans:
		ans[killer] += 1
	else:
		ans[killer] = 1

	dont_print[dead] = True

print 'HALL OF MURDERERS'
final_ans = []
for e in ans:
	if not e in dont_print:
		final_ans.append(e)	

final_ans.sort()
for e in final_ans:
	print e, ans[e]
