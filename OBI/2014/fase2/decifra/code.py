alpha = 'abcdefghijklmnopqrstuvwxyz'
new_alpha = raw_input()
new_relation = {}
for i in xrange(len(new_alpha)):
    new_relation[new_alpha[i]] = alpha[i]

word = raw_input()
answer = ''
for e in word:
    answer += new_relation[e]

print answer
