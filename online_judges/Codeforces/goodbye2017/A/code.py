s = raw_input()

turn = 'aeiou13579'
ans = 0
for e in s:
  if e in turn:
    ans += 1

print ans
