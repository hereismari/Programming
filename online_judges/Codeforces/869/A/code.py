n = int(raw_input())
ko = map(int, raw_input().split())
ka = map(int, raw_input().split())

m = {}
for e in ko: m[e] = 1
for e in ka: m[e] = 1

count = 0
for i in xrange(n):
  for j in xrange(n):
    if (ko[i] ^ ka[i]) in m:
      count += 1
      
if count % 2:
  print 'Koyomi'
else:
  print 'Karen' 
