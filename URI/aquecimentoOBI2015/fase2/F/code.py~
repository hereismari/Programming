numero = "0123456789"
s1 = raw_input()
s2 = raw_input()
s1 = list(s1)
s2 = list(s2)
NUM_CPF = 11
cpf = ""
valor1 = 0
valor2 = 0

valor_dec1 = 0
valor_dec2 = 0

cont_cpf = 0
for i in xrange(len(s1)):
    if s1[i] in numero:
        cpf += s1[i]
        s1[i] = 'a'
        cont_cpf += 1
    if cont_cpf >= NUM_CPF: break

flag = False
cont2 = 0
x = 10.0
for i in xrange(len(s1)):
   if(s1[i] in numero and not flag):
      valor1 = valor1*10 + int(s1[i])
   if(s1[i] in numero and flag and cont2 < 2):
      valor1 += int(s1[i])/x
      x = 100.0
      cont2 += 1
   if(s1[i] == '.'):
      flag = True

flag = False
cont2 = 0
x = 10.0
for i in xrange(len(s2)):
   if(s2[i] in numero and not flag):
      valor2 = valor2*10 + int(s2[i])
   if(s2[i] in numero and flag and cont2 < 2):
      valor2 += int(s2[i])/x
      x = 100.0
      cont2 += 1
   if(s2[i] == '.'):
      flag = True

print "cpf " + cpf
print "%.2f" % (valor1 + valor2)
#print "%s%c%02d" % (str(valor1 + valor2), '.', (valor_dec1 + valor_dec2) % 100)
