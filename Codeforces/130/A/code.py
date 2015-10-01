s = raw_input().split('WUB')
flag = True
for e in s:
    if flag and e == '': flag = False
    else: print e,
