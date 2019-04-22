l = int(raw_input())
c = int(raw_input())


print(l * c + max(l-1, 0) * max(c-1, 0))
print(max(l-1, 0) * 2 + max(c-1, 0) * 2)
