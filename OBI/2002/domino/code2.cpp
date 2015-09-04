#include <stdio.h>
#include <string.h>

int matriz[7][8], sol[7][8], nsols;
char marc[29];

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define PECA(min, max) ((15-min)*min/2 + max - min + 1)

void encaixa (int i, int j)
{
  int i2, j2, k, p;
  while (sol[i][j] != 0 && i < 7) /* Procura proxima posicao a ser preenchida */
    if (j < 7)
      j++;
    else
      {
        j = 0;
        i++;
      }
  if (i == 7) /* Encontrei uma solucao */    
    nsols++;
  else
    for (k = 0; k < 2; k++)
      {
	i2 = (k == 0? i : i + 1);
	j2 = (k == 0? j + 1 : j);
	if (i2 < 7 && j2 < 8)
	  {
	    p = PECA(MIN(matriz[i][j], matriz[i2][j2]), 
		     MAX(matriz[i][j], matriz[i2][j2]));
	    if (sol[i2][j2] == 0 && !marc[p])
	      {
		sol[i][j] = sol[i2][j2] = p;
		marc[p] = 1;
		encaixa (i, j);
		marc[p] = 0;
		sol[i][j] = sol[i2][j2] = 0;
	      }
	  }
      }
}

int main()
{
  int i, j, teste=1, ntestes;
  scanf("%d", &ntestes);
  for (teste=1; teste <= ntestes; teste++)
    {
      for (i = 0; i < 7; i++)
        for (j = 0; j < 8; j++)
          scanf("%d", &matriz[i][j]);
      memset (marc, 0, sizeof(marc));
      memset (sol, 0, sizeof(sol));
      nsols = 0;
      encaixa (0, 0);
      printf ("Teste %d\n%d\n\n", teste, nsols); 
    }
  return 0;
}
