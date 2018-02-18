n = int(raw_input())

for i in xrange(n):

  A, B, alpha, beta, y = map(int, raw_input().split())
  
  '''
  for j in xrange(y):
    # day 2
    matches = min(A, B)
    repro = (matches * 2)/100
    # alpha a
    a = (repro * alpha)/100
    # beta b
    b = (repro * beta) /100
    # rest of the babies
    repro -= (a + b)
    
    a += repro/2
    b += repro/2
    if(repro % 2):
      b += 1
    # day 3
    A -= (A)/100
    B -= (B)/100
    
    A += a
    B += b
  '''
  cont = 100
  for j in xrange(y):
    if cont == 0:
      break
    m = min(A, B)
    m = (m * 2)/100
    old_A = A
    old_B = B
    A = A - A/100 + (m + (m * alpha)/100 - (m * beta)/100)/2 
    B = B - B/100 + (m - (m * alpha)/100 + (m * beta)/100)/2
    if (m - (m * alpha)/100 - (m * beta)/100) % 2:
      B += 1
    
    if old_A == A and old_B == B:
      cont -= 1
    else:
      cont = 100
    
  print 'Case #%d: %d %d' % (i+1, A, B)
