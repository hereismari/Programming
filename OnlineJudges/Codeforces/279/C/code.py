big_num = raw_input()
l = len(big_num)

n, m = map(int, raw_input().split())

mod_n = [0] * l
mod_m = [0] * l

aux_n = 0
aux_m = 0

for i in xrange(l):
    
    aux_n = (aux_n * 10 + int(big_num[i])) % n
    aux_m = (aux_m * 10 + int(big_num[i])) % m

    mod_n[i] = aux_n
    mod_m[i] = aux_m

cont_10 = 1
for i in xrange(l-1, -1, -1):
    mod_m[i] = (mod_m[i] * cont_10) % m
    cont_10 = (10 * cont_10) % m

answer = False
for i in xrange(l):

    if mod_n[i] == 0 and i < l-1 and big_num[i+1] != '0' and mod_m[i] == mod_m[l-1]:
        answer = True
        print 'YES'
        index = i+1
        break

if not answer: print 'NO'
else:
    ans1 = ''
    ans2 = ''
    for i in xrange(index):
        ans1 += big_num[i]
    for i in xrange(index, l):
        ans2 += big_num[i]
    print ans1
    print ans2
