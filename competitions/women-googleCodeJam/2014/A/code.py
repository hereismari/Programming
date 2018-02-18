n = int(raw_input())

for i in xrange(n):
  s = raw_input()
  
  # actually...
  s = ' ' + s + ' '
  line1 = '+' + '-' * len(s) + '+'
  s = '|' + s + '|'
  
  print 'Case #%d:' % (i+1)
  print line1
  print s
  print line1
  
  
