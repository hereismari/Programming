
# pre process 

def getValue(s):

    res = ''
    cont = 0

    ant = ''
    for e in s:
        if e == ant: cont += 1
        else: 
            if cont != 0:
                res += str(cont)  
                res += ant
            cont = 1
            ant = e

    res += str(cont) + ant

    return res

ans = ["0", "3"]

for i in xrange(2, 41):
    ans.append(getValue(ans[i-1]))

# run

while True:

    try:
        x = int(raw_input())
    except:
        break

    print ans[x]
