while True:

    try:
        s = raw_input()
    except:
        break

    fila = 0
    flag = True

    for e in s:
        if e == '(':
            fila += 1
        elif e == ')':
            if fila <= 0:
                flag = False
            fila -= 1
    if fila == 0 and flag:
        print "correct"
    else:
        print "incorrect"
