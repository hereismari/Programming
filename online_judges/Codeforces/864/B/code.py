n = int(raw_input())
s = raw_input()

count = 0
max_count = 0
m = {}

for e in s:
  if e.islower():
    if not e in m:
      m[e] = 1
      count += 1
    if count > max_count:
      max_count = count
  else:
    count = 0
    m = {}

print max_count
        
