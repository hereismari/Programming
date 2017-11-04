t = int(raw_input())

def get_before(aux, n, d):
 x = aux - n
 while x < 0: x += d
 x = x % d
 return d if x == 0 else x
 
def get_after(aux, n, d):
 x = (aux + n) % d
 return d if x == 0 else x
 
for i in xrange(1, t+1):
  
  d, k, n = map(int, raw_input().split())
  n = n % d
  if (k % 2 == 1):
    new_pos = (k + n) % d
  else:
    new_pos = k - n
    while new_pos < 0:
      new_pos += d
    new_pos = new_pos % d
  
  if new_pos == 0: new_pos = d
  
  if new_pos == d: aux_right = 1
  else: aux_right = new_pos + 1
  
  if new_pos == 1: aux_left = d
  else: aux_left = new_pos - 1
  
  if k % 2 == 1:
    left = get_after(aux_left, n, d)
    right = get_after(aux_right, n, d)
  else:
    left = get_before(aux_left, n, d)
    right = get_before(aux_right, n, d)
    
  print 'Case #%d: %d %d' % (i, right, left)
