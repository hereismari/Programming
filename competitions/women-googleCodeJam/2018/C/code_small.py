perm = ['ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA']

t = int(raw_input())

for c in xrange(1, t+1):

  n = int(raw_input())
  names = raw_input().split()
  
  d = {name: False for name in names}
  
  for i in xrange(len(perm)):
    alphabet = perm[i]
    s = sorted(names, key=lambda word: [alphabet.index(c) if c in alphabet else ord(c) for c in word])
    
    #print s
    d[s[len(s)/2]] = True 
  
  #print d  
  print 'Case #%d:' % c,
  for i in xrange(2):
    if d[names[i]]:
      print 'YES',
    else:
      print 'NO',
  
  if d[names[-1]]:
      print 'YES'
  else:
    print 'NO'
