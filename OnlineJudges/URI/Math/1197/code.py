while True:
    try:
        n,m = map(int,raw_input().split())
    except:
        break
    print n*m*2
