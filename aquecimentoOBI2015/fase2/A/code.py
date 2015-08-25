n, m = map(int,raw_input().split())

if m >= 0 and  m <= 2: print "nova"
elif m >= 97 and m <= 100: print "cheia"
elif n > m : print "minguante"
else: print "crescente"
