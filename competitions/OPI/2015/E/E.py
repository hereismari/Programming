from datetime import date
a = map(int, raw_input().split(':'))
b = map(int,raw_input().split(':'))
d1 = date(a[0],a[1],a[2])
d2 = date(b[0],b[1],b[2])

print(abs(d1-d2).days)
