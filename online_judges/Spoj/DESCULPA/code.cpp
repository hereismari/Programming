#include <stdio.h>
#define MAX 10000
#define max(a,b) (a > b ? a : b)

using namespace std;

int m[MAX][MAX] = {0};
int v[MAX];
int w[MAX];
int r[MAX] = {0};

int knap(int n, int weight){

	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= weight; j++)
		{
			if(i == 0 || j == 0) m[i][j] = 0;
			else if(w[i-1] <= j)
				 m[i][j] = max(v[i-1] + m[i-1][j - w[i-1]], m[i-1][j]);
			else m[i][j] = m[i-1][j];
		}
	}

	return m[n][weight];
}

int weight,n;
int x,y;

int main(){
	int cont = 1;	
	while(1){
		scanf("%d %d",&weight,&n);
		if(weight == 0 && n ==0) break;
		for(int i = 0 ; i < n ; i++)
			scanf("%d %d",&w[i],&v[i]);
		printf("Teste %d\n",cont++);
		printf("%d\n\n",knap(n,weight));
	}
	return 0;
}
