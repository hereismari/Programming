#include <bits/stdc++.h>
#define MAX 111
#define INF 1000010

using namespace std;

int adj[MAX][MAX];

void floyd(){

	for(int k = 1; k <= 20; k++)
		for(int i = 1; i <= 20; i++)
			for(int j = 1; j <= 20; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main(){

	int d;
	int x,y;
	int n;	
	int cont = 1;

	while(scanf("%d",&d) != EOF){
		for(int i = 1; i < MAX; i++)
			for(int j = 1 ; j < MAX; j++)
				adj[i][j] = INF;
	
		for(int i = 0 ; i < d; i++){
			scanf("%d",&x);
			adj[1][x] = 1;
			adj[x][1] = 1;
		}
	
		for(int i = 2 ; i <= 19; i++)
		{
			scanf("%d",&d);
			for(int j = 0 ; j < d; j++)
			{
				scanf("%d",&x);
				adj[i][x] = 1;
				adj[x][i] = 1;
			}
		}	

		floyd();
		scanf("%d",&n);
		printf("Test Set #%d\n",cont++);
		for(int i = 0 ; i < n; i++){
			scanf("%d %d",&x,&y);	
			printf("%2d to %2d: %d\n",x,y, adj[x][y]);
		}
		printf("\n");
	}
	
	return 0;

}
