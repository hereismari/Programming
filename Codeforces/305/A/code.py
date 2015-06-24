s = raw_input()
k = int(raw_input())

length = len(s)
num_palindromes = length/k

palindrome = True

s1 = ""
for i in range(length):
	s1 += s[i]
	if(len(s1) == num_palindromes):
		palindrome = (s1[::] == s1[::-1])
		if palindrome == False: break
		s1 = ""

if palindrome and length % k == 0: print "YES"
else : print "NO"


