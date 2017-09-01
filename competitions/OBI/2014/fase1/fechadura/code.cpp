#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#define MAX 1001
using namespace std;

int n, m;
int pinos1[MAX];
int pinos2[MAX];
int quant;
int cont1,cont2;
int x;
int main(){

	scanf("%d %d",&n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&x);
		pinos2[i] = x;
		pinos1[i] = x;
	}
		
	quant = 0;
	cont1 = 0;
	cont2 = 0;

	for(int i = 0; i < n; i++){
		pinos1[i] += quant;
		quant = m - pinos1[i]; 
		cont1 += abs(quant);
	}

	quant = 0;
	for(int i = n-1; i >= 0; i--){
		pinos2[i] += quant;
		quant = m - pinos2[i]; 
		cont2 += abs(quant);
	}
	
	printf("%d\n",cont1 < cont2?cont1:cont2);
	return 0;
}


