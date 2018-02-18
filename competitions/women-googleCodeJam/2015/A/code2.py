t = int(raw_input())

for k in xrange(1, t+1):

  n = int(raw_input())
  s = raw_input()
  
  aux = ''
  res = ''
  for i in xrange(len(s)):
    if i % 8 == 0 and i != 0:
        res += ''.join([chr(int(aux, 2))])
        aux = ''
    if s[i] == 'I': aux += '1'
    else: aux += '0'    

  
  res += ''.join([chr(int(aux, 2))])
  print 'Case #%d:' % k, res
