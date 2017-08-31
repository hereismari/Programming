while True:
   h1,m1,h2,m2 = map(int,raw_input().split())
   if (h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0):
	break
   horas = 0
   minutos = 0
   
   if (h1 == h2):
	if (m1 > m2):
		horas = 24
	else:
		horas = 0
	minutos = m2 - m1

   elif (h1 > h2 and h2 != 0):
	horas = 24 - (h1 - h2)
   else:
	if h2 == 0:
	   h2=24
	horas = h2 - h1
   minutos = m2 - m1
   print horas * 60 + minutos
