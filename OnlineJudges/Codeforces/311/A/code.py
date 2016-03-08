n = int(raw_input())

min1,max1 = map(int,raw_input().split())
min2,max2 = map(int,raw_input().split())
min3,max3 = map(int,raw_input().split())

answer1 = min1
answer2 = min2
answer3 = min3


answer = answer1 + answer2 + answer3 #at least...
if (answer < n):
	answer1 = min(max1,n-answer + min1)
answer = answer1 + answer2 + answer3 #updating...

if (answer < n):
	answer2 = min(max2,n-answer + min2)
answer = answer1 + answer2 + answer3 #updating...

if (answer < n):
	answer3 = min(max3,n-answer + min3)

print answer1,answer2,answer3
