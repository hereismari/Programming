
#include <stdio.h>

int temperatura[10000], n, m;

int main()
{
  int i, maior, menor, soma, teste=1;
  while (scanf("%d %d", &n, &m) == 2 && n > 0)
    {
      soma = 0;
      for (i = 0; i < m; i++)
	{
	  scanf("%d", &temperatura[i]);
	  soma += temperatura[i];
	}
      maior = menor = soma;
      for (; i < n; i++)
	{
	  scanf("%d", &temperatura[i]);
	  soma = soma + temperatura[i] - temperatura[i-m];
	  if (soma > maior)
	    maior = soma;
	  if (soma < menor)
	    menor = soma;
	}
      printf("Teste %d\n%d %d\n\n", teste++, menor/m, maior/m);
    }
  return 0;
}