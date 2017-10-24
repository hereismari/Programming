MAX = 200001

n = int(raw_input())
a = map(int, raw_input().split())

count = [0] * MAX
can_use = [False] * MAX
zero = []
changes = 0

for i in xrange(n):
  count[a[i]] += 1
  if count[a[i]] > 1:
    changes += 1

for i in xrange(1, n+1):
  if count[i] == 0:
    zero.append(i)

j = 0
for i in xrange(n):
  if j >= len(zero): break
  
  if a[i] > zero[j] and count[a[i]] > 1:
    count[a[i]] -= 1
    a[i] = zero[j]
    j += 1
  elif a[i] < zero[j] and count[a[i]] > 1:
    if can_use[a[i]]:
      count[a[i]] -= 1
      a[i] = zero[j]
      j += 1
    else:
      can_use[a[i]] = True

ans = str(a[0])
for i in xrange(1, n):
  ans += ' ' + str(a[i])

print changes
print ans
