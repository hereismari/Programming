a, b, c , d = map(int, raw_input().split())

p = 1.0 * a / b
q = (1.0 - 1.0 * c / d) * (1.0 - 1.0 * a / b)

print p/(1-q)
