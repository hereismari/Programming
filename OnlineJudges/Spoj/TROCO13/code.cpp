#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#define MAX 100010
using namespace std;

int v,m;
int x;
int moedas[MAX];
bool possible[MAX];

int main(){

	scanf("%d %d",&v,&m);
	for(int i = 0 ; i < m ; i++)
		scanf("%d",&moedas[i]);
	
	possible[0] = true;
	for(int i = 1; i <= v ; i++)
		possible[i] = false;

	for(int i = 0 ; i < m; i++)
		for(int j = v; j >= moedas[i]; j--)
			if(possible[j - moedas[i]])
				possible[j] = true;

	printf("%c\n",possible[v]?'S':'N');
	return 0;
}


