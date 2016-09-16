while True:

	n = int(input())
	if n == 0:
		break

	center = map(int, input().split())
	for i in range(n):
		pos = map(int, input().split())
                if (pos[0] == center[0] or pos[1] == center[1]):
			print ("divisa")
		elif (pos[0] > center[0] and pos[1] > center[1]):
			print ("NE")
		elif (pos[0] > center[0] and pos[1] < center[1]):
			print ("SE")
		elif (pos[0] < center[0] and pos[1] < center[1]):
			print ("SO")
		else:
			print ("NO")
