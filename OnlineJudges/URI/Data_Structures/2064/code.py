# definindo variaveis
letters = 'qwertyuioplkjhgfdsazxcvbnm'
fav_letters = ''

conn = {}
value = {}
str_ans = {}
ans = 0

# inicialmente valor de todas as letras eh 0 e cada letra esta conectada com ela mesma
for e in letters: 
    conn[e] = e
    value[e] = 0

def getValue():
    v = 0
    for e in fav_letters: v += value[e]
    return v

# conecta duas letras e recalcula valor
def connect(a, b, ans):

    for e in letters:
        if conn[e] == a: pos_a = e
        if conn[e] == b: pos_b = e

    aux = conn[pos_a]
    conn[pos_a] = conn[pos_b]
    conn[pos_b] = aux

    aux = value[a]
    value[a] = value[b]
    value[b] = aux

    new_value = getValue()
    if new_value > ans:
        for e in letters:
	    str_ans[e] = conn[e]
        ans = new_value
    return ans

k, m, n = map(int, raw_input().split())

fav_letters = raw_input()
s = raw_input()

for e in s: 
    value[e] += 1
    str_ans[e] = conn[e]

ans = getValue()
for i in xrange(n):
    x, y = raw_input().split()
    ans = connect(x, y, ans)

final_str = ''
for e in s:
    final_str += str_ans[e]

print ans
print final_str
