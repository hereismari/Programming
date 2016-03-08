n = int(raw_input())
sala = [0]*(n+1)
res = [0]*(n+1)
aux = []

for i in xrange(1,n+1):
    acao, codigo = raw_input().split()
    if acao == "+":
        sala[i] = sala[i-1] + 1
        aux.append(codigo)
        res[i] = 2
    elif acao == '-' and not codigo in aux:
        res[i] = 1
        sala[i] = sala[i-1]
    elif acao == '-':
        sala[i] = sala[i-1] - 1
        aux.remove(codigo)

#print sala
i = n
while i >= 0:
    if res[i] == 1:
        j = i
        while j >= 0:
            if res[j] == 2: sala[j] += 1
            if j == 0: sala[j] += 1
            j -= 1
    i -= 1
#print res
#print sala
ans = 0
for e in sala:
    ans = max(ans,e)
print ans
