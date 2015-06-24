#include <stdio.h>
#include <math.h>
#define MAX 1001

using namespace std;

int array[MAX];
int maior;
int index_maior;
int saida;
int n,k;

int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&k);
		maior = 0;
		for(int j = 0 ; j < k ; j++){
			scanf("%d",&array[j]);
			if (array[j] > maior){
				maior = array[j];
				index_maior = j;}
	}

	while(maior <= saida) {
		saida = maior;
		array[index_maior] = ceil(array[index_maior]/2.0);
		for(int j = 0 ; j < k ; j++)
			if(array[j] > maior){
				maior = array[j];
				index_maior = j;
			}
		maior += 1;
		array[index_maior]+=1;

	}
	printf("Case #%d: %d\n",i+1,saida);
}

	return 0;
}
