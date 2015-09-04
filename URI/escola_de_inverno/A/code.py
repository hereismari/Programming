n,m,k = map(int,raw_input().split())

if (m < n and m <= k):
	print ":)"
elif (m > n and k <= m):
	print ":("
elif (m > n and k > m and k-m < m-n):
	print ":("
elif (m > n and k > m and k-m >= m-n):
	print ":)"
elif m < n and k < m and m-k < n-m:
	print ":)"
elif m < n and k < m and m-k >= n-m:
	print ":("
elif n == m and k > m:
	print ":)"
else:
	print":("

