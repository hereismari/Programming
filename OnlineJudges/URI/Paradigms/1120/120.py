while True:
   n,s = raw_input().split()
   if n == '0' and s == '0':
        break
   
   saida = ""
   for e in s:
      if e != n:
	if e != '0' or (e == '0' and saida != ""):
	   saida += e
   if saida == "":
      saida = "0"
   print saida
   
   
   
   

