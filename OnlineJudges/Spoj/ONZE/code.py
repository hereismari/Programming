
while True:
       n = raw_input()
       ncopy = int(n)

       if ncopy == 0: break

       if ncopy % 11 == 0: print "%s is a multiple of 11." % n
       else: print "%s is not a multiple of 11." % n
