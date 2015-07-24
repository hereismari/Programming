str1 = raw_input()
str2 = raw_input()
str3 = raw_input()
str4 = raw_input()

l = [str1[2::],str2[2::],str3[2::],str4[2::]]
l2 = [str1,str2,str3,str4]
m = 0
n = 1000
saida1 = ""
saida2 = ""
for i in range(4):
    if len(l[i]) > m:
        m = len(l[i])
        saida1 = l2[i]
    if len(l[i]) < n:
        n = len(l[i])
        saida2 = l2[i]
cont1 = 0
cont2 = 0
pode1 = True
pode2 = True

for e in l:
    if len(e) == m:
        cont1 += 1
    if len(e) == n:
        cont2 += 1
    if(m < 2*len(e) and m != len(e)):
        pode1 = False
    if(n*2 > len(e) and n != len(e)):
        pode2 = False
if cont1 > 1:
    pode1 = False
if cont2 > 1:
    pode2 = False
    
if pode1 and pode2:
    print 'C'
elif pode1:
    print saida1[0]
elif pode2:
    print saida2[0]
else:
    print 'C'
