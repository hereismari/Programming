def gen_alpha(main, sec):

  alpha = ''
  i = 0
  for c in main:
    if c not in alpha:
      alpha += c
    if main[i] != sec[i]: break
    i += 1
    
  for c in sec:
    if c not in alpha:
      alpha += c
  
  #print alpha
  return alpha

def gen_inv_alpha(main, sec):

  alpha = ''
  i = 0
  for c in main[::-1]:
    if c not in alpha:
      alpha += c
    if main[i] == sec[i]: break
    i += 1
    
  for c in sec[::-1]:
    if c not in alpha:
      alpha += c
  
  #print alpha
  return alpha

t = int(raw_input())

for c in xrange(1, t+1):

  n = int(raw_input())
  names = raw_input().split()
  
  d = {name: False for name in names}
  
  for i in xrange(3):
    for j in xrange(3):
      if i != j:
        alphabet = gen_alpha(names[j], names[i])
        s = sorted(names, key=lambda word: [alphabet.index(c) if c in alphabet else ord(c) for c in word])
        d[s[len(s)/2]] = True
        alphabet = gen_inv_alpha(names[j], names[i])
        s = sorted(names, key=lambda word: [alphabet.index(c) if c in alphabet else ord(c) for c in word])
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
