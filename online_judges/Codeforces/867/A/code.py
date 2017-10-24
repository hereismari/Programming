n = int(raw_input())
s = raw_input()

count_s_f = 0
count_f_s = 0

for i in xrange(1, n):
  if s[i-1] == 'F' and s[i] == 'S':
    count_f_s += 1
  elif s[i-1] == 'S' and s[i] == 'F':
    count_s_f += 1

if count_s_f > count_f_s:
  print 'YES'
else:
  print 'NO'
