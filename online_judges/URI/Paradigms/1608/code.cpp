#include <stdio.h>
#define MAX 101
using namespace std;

int t;
int d,n,b,q;
int quant, index;
int ingredients[MAX];
int bolos[MAX];
int soma;
int min;

int main(){

	scanf("%d",&t);
	for(int i = 0 ; i < t; i++){
		scanf("%d %d %d",&d,&n,&b);
		for(int j = 0 ; j < n; j++)
			scanf("%d",&ingredients[j]);
		for(int j = 0 ; j < b ; j++)
		{
			soma = 0;
			scanf("%d",&q);
			for(int k = 0 ; k < q; k++)
				{
					scanf("%d %d",&index,&quant);
					soma += ingredients[index]*quant;
				}
			bolos[j] = soma;
		}

		min = bolos[0];
		for(int j = 0; j< b; j++)
			if(bolos[j] < min)
				min = bolos[j];

		printf("%d\n",d/min);

	}

	return 0;
}
