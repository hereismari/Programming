#include <stdio.h>
#include <math.h>
#define MAX 1001
using namespace std;

int main(){

	int F,R,x,ant = 0;
	int maior = 0,valor = 0;
	scanf("%d %d",&F,&R);

	scanf("%d",&x);
	maior = x - 1;
	ant = x;

	for(int i = 1 ; i < R ; i++){
		
		scanf("%d",&x);
		valor = ceil((x - ant - 1)/2.0);
		if(valor > maior)
			maior = valor;
		
		ant = x;
	}	
	
	valor = F - ant;
	if(valor > maior)
		maior = valor;

	printf("%d\n",maior);
	return 0;
}
