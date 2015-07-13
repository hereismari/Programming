def is_vowel(a):
	return a in 'aoyeuiAOEYEUI'

s = raw_input()

ans = ""
for e in s:
	if not is_vowel(e):
		ans += "."+e.lower()

print ans
