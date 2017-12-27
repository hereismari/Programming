t = int(raw_input())

for i in xrange(t):

  n, m = map(int, raw_input().split())
  aux = 0
  aux2 = 0
  cont = 0
  for k in xrange(n):
    x = map(int, raw_input().split())
    j = 0
    while j < m and x[j] != 1:
      aux += 1
    if j < m:
      cont += 1
    else:
      aux = 0
    aux2 += aux

  if i < t-1:
    blank_line = raw_input()
  
  if cont == 0:
    if n * m % 2 == 0:
      print 'SECOND'
    else:
      print 'FIRST'
  elif (aux2 + cont) % 2 == 0:
    print 'SECOND'
  else:
    print 'FIRST'
     
