

name = ["zero","one","two","three","four","five","six","seven","eight", "nine", "ten", "eleven","twelve","thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen"]

name2 = ["twenty","thirty","forty","fifty", "sixty", "seventy", "eighty","ninety"];

s = ""
n = raw_input()

if(int(n) < 20):
	print name[int(n)]
else:
	if( int(n) % 10 == 0): print name2[int(n[0])-2]
	else: print name2[int(n[0])-2] +"-" +name[int(n[1])]
