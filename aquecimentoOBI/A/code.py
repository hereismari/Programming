n = int(raw_input())

la,lb = map(int, raw_input().split())
sa,sb = map(int, raw_input().split())

if n < la or n < sa: print 'impossivel'
elif n > lb or n > sb: print 'impossivel'
else: print 'possivel'
	
