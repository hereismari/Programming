#include <bits/stdc++.h>
#define MAX 300

using namespace std;
int graph[20][20]; /* grafo */
int used[20];      /* vertice escolhido ou vizinho a vertice escolhido */
int ns;            /* numero de vertices da solucao parcial */
int max;           /* numero de vertices da melhor solucao */
int n;             /* numero de vertices */

void search ( int i )
{
  int j,k;

  if( ns > max)    /* se solucao parcial melhor que melhor solucao */
    max = ns;

  for (j=i;j<n;j++)  /* testa todas as combinacoes sem repetir 2 3 e 3 2 */
                     /* pois o j eh maior ou igual a i                   */
    if( !used[j] )   /* se vertice esta disponivel */
      {
	used[j] = 1;  /* vertice incorporado na solucao parcial */
	for(k=j+1;k<n;k++)
	  {
	    if(graph[j][k])
	      used[k]++;  /* atualiza em used os vizinhos do novo vertice */
	  }
	ns++;        /* aumenta tamanho da solucao parcial */
	search(j+1); /****** RECURSAO ******/
	ns--;        /* diminui tamanho da solucao parcial */
	for(k=j+1;k<n;k++)
	  {
	    if(graph[j][k]) 
	      used[k]--;    /* libera vizinhos */
	  }
	used[j] = 0; /* libera vertice utilizado na solucao parcial */
      }

  return;
}

int main ( void )
{
  int i,d,teste=1;

  while (scanf("%d",&n)==1 && n)
    {
      memset(graph,0,sizeof(graph)); /* zera estruturas de dados */
      memset(used,0,sizeof(used));
      max=0;

      for (i=0;i<n;i++)
	{
	  while(scanf("%d",&d)==1 && d) /* entrada */
	    {
	      d--;
	      graph[i][d] = 1;
	      graph[d][i] = 1;
	    }
	}
      
      search(0); /* busca backtracking */

      printf("Teste %d\n%d\n\n",teste++,max);
    }


  return 0;
}



