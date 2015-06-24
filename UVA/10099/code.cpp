#include <bits/stdc++.h>
#define MAX 110
#define INF -1

using namespace std;

int adj[MAX][MAX];
void clearAdj() { for(int i = 0; i < MAX; i++) for(int j = 0 ; j < MAX; j++)adj[i][j] = INF;}

void floyd(int x){

	for(int k = 1; k <= x; k++)
		for(int i = 1; i <= x; i++)
			for(int j = 1; j <= x; j++)
				adj[i][j] = max(adj[i][j],min(adj[i][k],adj[k][j]));
}


int main(){
	int n,m;
	int x,y,w;	
	int cont = 1;
	while(1){

		scanf("%d %d",&m,&n);
		if(n == 0) break;
		clearAdj();
		for(int i = 0; i < n; i++){
			scanf("%d %d %d",&x,&y,&w);
			adj[x][y] = w;
			adj[y][x] = w;
		}
		for(int i = 0 ;i <= m; i++) adj[i][i] = 0;
		floyd(m);
		scanf("%d %d %d",&x,&y,&w);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cont++,x!=y?(w+adj[x][y]-2)/(adj[x][y]-1): 0);

	}
	return 0;
}
