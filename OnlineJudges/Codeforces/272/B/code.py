global miss, right_place

miss = 0.0
right_place = 0.0

def dfs(counter, pa):
    global miss, right_place
    if counter == len(s1) or counter >= len(s2):
        if pa == pos1: right_place += 1
        else: miss += 1
    else:
        if s2[counter] == '+': dfs(counter+1, pa+1)
        elif s2[counter] == '-': dfs(counter+1, pa-1)
        else:
            dfs(counter+1, pa+1)
            dfs(counter+1, pa-1)

s1 = raw_input()
s2 = raw_input()

pos1 = 0
for e in s1:
    if e == '+': pos1 += 1
    else: pos1 -= 1

dfs(0, 0.0)

total = miss + right_place
print ("%.10f") % (right_place / total)
