from random import random

ans = ''
cont = 0
for i in xrange(200):

    if i % 2 == 1:
        if int((random() * 2)) > 0: ans += '+'
        else: ans += '-'
    else:
         cont += 1
         ans += '?'
    ans += ' '

ans += '= '
ans += '1000000'
print cont
print ans
