n = int(raw_input())
caixas = map(int, raw_input().split())

caixas.sort()

possible = True
ca = 0
for caixa in caixas:
	if abs(caixa-ca) > 8:
		possible = False
		break
	ca = caixa

print('S' if possible else 'N')
