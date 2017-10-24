n = int(raw_input())

count = [0] * 101
dif_numbers = 0
for i in xrange(n):
  x = int(raw_input())
  if count[x] == 0: dif_numbers += 1
  count[x] += 1

if dif_numbers != 2:
  print "NO"
else:
  c = 0
  flag = True
  v = []
  for i in xrange(1, 101):
    if c != 0 and count[i] > 0 and count[i] != c:
      flag = False
    elif count[i] != 0:
      c = count[i]
      v.append(i)
  if flag:
    print "YES"
    print v[0], v[1]
  else:
    print "NO"
