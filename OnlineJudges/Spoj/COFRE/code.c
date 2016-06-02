#include <stdio.h>

int main()
{
  int n, total_joao, total_ze, deposito_joao, deposito_ze, teste=1, i;
  while (scanf("%d", &n) == 1 && n > 0)
    {
      total_joao = 0;
      total_ze = 0;
      printf("Teste %d\n", teste++);
      for (i = 0; i < n; i++)
	{
	  scanf("%d %d", &deposito_joao, &deposito_ze);
	  total_joao += deposito_joao;
	  total_ze += deposito_ze;
	  printf("%d\n", total_joao - total_ze);
	}
      printf("\n");
    }
  return 0;
}