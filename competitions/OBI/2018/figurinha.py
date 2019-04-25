n, m, c = map(int, raw_input().split())

l1 = set(map(int, raw_input().split()))
l2 = set(map(int, raw_input().split()))
print(len(l1-l2))
