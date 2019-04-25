n, c, m = map(int, raw_input().split())
carimbadas = set(raw_input().split())
figurinhas = set(raw_input().split())
print(len(carimbadas - figurinhas))
