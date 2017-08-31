m, s = map(int,raw_input().split())

aux_s = s
str1 = []

while len(str1) != m:
    if(aux_s >= 9):
        str1.append(9)
        aux_s -= 9
    else:
        str1.append(aux_s)
        aux_s -= aux_s

i = 0
j = m - 1
str2 = str1[::]

while(i < j):
    
    a1 = str2[i]
    a2 = 9 - str2[j]
    
    if i == 0: a1 -= 1
    
    aux = min(a1,a2)
    str2[i] -= aux
    str2[j] += aux
  
    if(aux == a1): i += 1
    else: j -= 1
     
if m == 1 and s == 0:
    print 0,0
elif (9 * m < s) or s == 0:
    print -1,-1
else:
    print ''.join(map(str, str2)),''.join(map(str, str1))
