def bsearch(num, l): 

    low = 0
    high = len(l)-1
    
    while(low <= high):
        
        mid = (low + high)/2
        
        if a[mid] > num: high = mid - 1
        elif a[mid] < num: low = mid + 1
        elif low != high: high = mid
        else: return mid

    return -1

n, m = map(int, raw_input().split())

a = map(int, raw_input().split())

for i in xrange(m):
    x = int(raw_input())
    print bsearch(x, a)
