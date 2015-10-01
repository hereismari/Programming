UPPER = 'QWERTYUIOPASDFGHJKLZXCVBNM'
LOWER = 'qwertyuiopasdfghjklzxcvbnm'

def case1(word):
    ans = word[0] in LOWER
    for e in word[1::]:
        ans &= e in UPPER
    return ans

def case2(word):
    for e in ans:
        if not e in UPPER: return False
    return True

def change(word):
    ans = ''
    for e in word:
        if e in UPPER:
            ans += e.lower()
        else:
            ans += e.upper()
    return ans

s = raw_input()
ans = s
if case1(s) or case2(s):
    ans = change(s)

print ans
