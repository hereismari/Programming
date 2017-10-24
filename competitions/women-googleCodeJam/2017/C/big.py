t = int(raw_input())

def start_matrix(d):
  cont = 0
  m = [['/' for j in xrange(d)] for k in range(d)]
  for i in xrange(d):
    for j in xrange(d):
      if i % 2 == 0:
        if cont % 2 == 0:
          m[i][j] = 'I'
        else:
          m[i][j] = 'O'
        cont += 1
      else:
        m[i][j] = '/'
  
  return m  
    
def update(m, n):
  i_3 = 1
  j_3 = 1
  
  i_1 = 1
  j_1 = 0
  
  while n != 0:
    if n % 3 == 0 and i_3 < d and j_3 < d:
      m[i_3][j_3] = 'O'
      n -= 3
      if j_3 + 1 >= 14:
        i_3 += 2
        j_3 = 1
      else:
        j_3 += 1
    else:
      m[i_1][j_1] = 'O'
      if j_1 == 14:
        j_1 = 0
        i_1 += 2
      else:
        j_1 = 14
      
      n -= 1

for i in xrange(1, t+1):

  d, n = map(int, raw_input().split())
  
  m = start_matrix(d)
  update(m, 287-n)

  print 'Case #%d:' % (i)
  for j in xrange(d):
    print ''.join(m[j])

 
