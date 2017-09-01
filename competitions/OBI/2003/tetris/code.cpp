#include <bits/stdc++.h>
#define MAX_CHAR 20
#define MAX 10011

using namespace std;

struct jogador{

	char nome[MAX_CHAR];
	int pontuacao;
	
};

bool comp(jogador j1, jogador j2){
	
	if(j1.pontuacao != j2.pontuacao)
		return j1.pontuacao > j2.pontuacao;
		
	return (strcmp(j1.nome,j2.nome) < 0);
	
}

int main() {

	int n,x;
	jogador jogadores[MAX];
	int cont = 1;
	while(1){
		jogadores[0].pontuacao = -1;
		scanf("%d",&n);
		if(n == 0) break;
		if (cont > 1) printf("\n");


		for(int i = 1 ; i <= n ; i++){
			
			scanf("\n%s",jogadores[i].nome);
			
			jogadores[i].pontuacao = 0;
			int maior = 0;
			int menor = MAX;
			for(int j = 0; j < 12; j++) 
			{
				scanf("%d",&x);
				jogadores[i].pontuacao += x;
				if(x > maior) maior = x;
				if(x < menor) menor = x;
			}
			
			jogadores[i].pontuacao -= (maior + menor);
			
		}
		
		sort(jogadores+1,jogadores+n+1,comp);
		
		printf("Teste %d\n",cont++);
		for(int i = 1, j = 0 ; i <= n ; i++){
			
			if(jogadores[i-1].pontuacao != jogadores[i].pontuacao) j=i;
			printf("%d %d %s\n",j, jogadores[i].pontuacao,jogadores[i].nome);
		}
		
	}
	
	return 0;
}
