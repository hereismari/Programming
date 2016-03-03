#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100001

using namespace std;

int n,m,x;
int cartas1[MAX];
int cartas2[MAX];

int main(){

	while(1){
	
		scanf("%d %d",&n, &m);
		if (n == 0 && m ==0)
			break;
		
		memset(cartas1,0,sizeof(cartas1));	
		memset(cartas2,0,sizeof(cartas2));
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&x);
			cartas1[x]++;
		}

		for(int i = 0 ; i < m ; i++){
			scanf("%d",&x);
			cartas2[x]++;
		}

		int cont1 = 0;
		int cont2 = 0;
		for(int i = 0 ; i < MAX ; i++){
			if(cartas1[i] > 0 && cartas2[i] == 0)
				cont1++;
			if(cartas1[i] == 0 && cartas2[i] > 0)
				cont2++;
		}

		printf("%d\n",cont1 < cont2 ? cont1: cont2);

	}

	return 0;
}
