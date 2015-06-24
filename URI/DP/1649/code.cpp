#include <stdio.h>

#define MAX 103

using namespace std;

int n,m,r,c;
int matriz[MAX][MAX];

int main(){

	while(1){

		scanf("%d %d %d %d",&n,&m,&r,&c);	
		if(n == 0 && m == 0 && r == 0 && c == 0)
			break;
		
		for(int i = 0 ; i < MAX ; i++){
			matriz[i][0] = 0;
			matriz[0][i] = 0;
			matriz[MAX-1][0] = 0;
			matriz[0][MAX-1] = 0;
		}
	
		for(int i = 1 ; i <= n ;i++)
			for(int j = 1 j <= m;j++)
				scanf("%d",matriz[i][j]);
		int x = 0;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j<= m;j++)
				x = verifica(i,j,r,c);
		printf("x == 0?:
	}



}
