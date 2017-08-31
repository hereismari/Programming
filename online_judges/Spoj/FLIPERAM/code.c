#include <stdio.h>

int main()
{

void ordenar (int num[],int tam);
int num,maiores[10000],pontuacao,i,k,l,hold,aux,ranking;
scanf("%d%d",&num,&ranking);
  for(i=0;i<num;i++)
    scanf("%d",&maiores[i]);
    ordenar(maiores,num);
    for(i=0;i<ranking;i++)
    printf("%d\n",maiores[i]);
return 0;
}

void ordenar (int num[], int tam)
{
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
   {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j] > num[min]) {
        min = j;
      }
    }
    if (i != min) {
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
}