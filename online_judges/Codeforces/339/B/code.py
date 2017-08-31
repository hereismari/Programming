def isBeautiful(s):
    flag = False
    for e in s:
        if e not in ['1', '0']: return False
        if e == '1' and flag: return False
        if e == '1': flag = True
    return True

def zeros(s):
    cont = 0
    for e in s:
        if e == '0': cont += 1
    return cont

n = int(raw_input())
l = raw_input().split()

ans = 0
front = ""

zero = False

for e in l:
    if isBeautiful(e):
        if e == '0': zero = True
        else: ans += zeros(e)
    else:
        front = e
if not zero: 
    if front == "": front = '1'
    ans2 = front + ans * '0'
    print ans2
else: print '0'
