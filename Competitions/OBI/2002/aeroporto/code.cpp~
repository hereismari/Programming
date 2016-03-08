#include <stdio.h>
#include <string.h>

int nvoos[101];

int main()
{
  int a, v, x, y, teste=1, max, i;
  while (scanf("%d %d", &a, &v) == 2 && a > 0)
    {
      memset(nvoos, 0, sizeof(nvoos));
      while (v-- > 0)
	{
	  scanf("%d %d", &x, &y);
	  nvoos[x]++;
	  nvoos[y]++;
	}
      max = nvoos[1];
      for (i = 2; i <= a; i++)
	if (nvoos[i] > max)
	  max = nvoos[i];
      printf("Teste %d\n", teste++);
      for (i = 1; i <= a; i++)
	if (nvoos[i] == max)
	  printf("%d ", i);
      printf("\n\n");
    }
  return 0;
}
