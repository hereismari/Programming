a, b, f, k = map(int, raw_input().split())

gas = b 
flag = True
ans = 0
used_gas = [False] * (2 * k + 1)

i = 0
while i < k:
  if i % 2 == 0:
    if gas >= a:
      gas -= a
      i += 1
    elif gas >= f and b >= a-f:
      gas = b-(a-f)
      ans += 1
      used_gas[i] = True
      i += 1
    elif i != 0 and not used_gas[i-1] and b >= f:
      gas = b-f
      ans += 1
      used_gas[i-1] = True
    else:
      flag = False
      break
  else:
    if gas >= a:
      gas -= a
      i += 1
    elif gas >= a-f and b >= f:
      gas = b-f
      ans += 1
      used_gas[i] = True
      i += 1
    elif i != 0 and not used_gas[i-1] and b >= a-f:
      gas = b-(a-f)
      ans += 1
      used_gas[i-1] = True
    else:
      flag = False
      break
  
if not flag:
  print -1
else:
  print ans
  i += 1
