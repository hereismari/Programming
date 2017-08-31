def sortted(l):
    for i in xrange(1,len(l)):
        if l[i] < l[i-1]: return False
    return True

n = int(raw_input())
a = map(int, raw_input().split())

while not sortted(a):

    for i in xrange(1, n):
        if a[i] < a[i-1]:
            j = i -1
            while j >= 0 and a[j+1] < a[j]:
                print j+1, j+2
                aux = a[j]
                a[j] = a[j+1]
                a[j+1] = aux
