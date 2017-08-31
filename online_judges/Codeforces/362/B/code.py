s = raw_input().split('e')
b = int(s[1])

zeros = s[0][0] == "0"
part = ["", ""]

part[0] = s[0][0]

i = 2
p = 0
count = 0

while i < len(s[0]):

    count += 1
    if count > b: p = 1
    part[p] += s[0][i]
    i += 1

while count < b:
    count += 1
    part[0] = part[0] + '0'

i = 0
while i < len(part[0]) and len(part[0]) > 1 and part[0][i] == '0': 
    i += 1

j = 0
while j < len(part[1]) and part[1][j] == '0': 
    j += 1

if len(part[1]) and j < len(part[1]):
    print part[0][i::] + '.' + part[1]
else:
    print part[0][i::]
