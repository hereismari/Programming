# your code goes here

minC = [0]*26
maiC = [0]*26

minN = [0]*26
maiN = [0]*26

a = ord('a')
A = ord('A')

n = raw_input()
for e in n:
    if e.islower():
        minC[ord(e) - a] += 1
    else:
        maiC[ord(e) - A] += 1

m = raw_input()
for e in m:
    if e.islower():
        minN[ord(e) - a] += 1
    else:
        maiN[ord(e) - A] += 1
        
ans1 = 0
ans2 = 0

for i in range(26):
    
    ans1 += min(maiN[i],maiC[i])
    k = min(maiN[i],maiC[i])
    maiN[i] -=  k
    maiC[i] -=  k
    
    ans1 += min(minN[i],minC[i])
    k = min(minN[i],minC[i])
    minN[i] -=  k
    minC[i] -=  k
    
    ans2 += min(maiN[i],minC[i]) + min(maiC[i],minN[i])

print ans1, ans2
