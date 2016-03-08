#include <bits/stdc++.h>
#define INF 100000
#define MAX 50

using namespace std;

int adj[MAX+1][MAX+1];
int next[MAX + 1][MAX + 1];

void floyd(){

	for(int k = 1; k <= MAX; k++)
		for(int i = 1; i <= MAX; i++)
			for(int j = 1; j <= MAX; j++)
			{
				if(adj[i][k] + adj[k][j] < adj[i][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
					next[i][j] = next[k][j];
				}
			}
}

void path(int x, int y){

	if(next[x][y] == x){
		printf(" %d",next[x][y]);
		return;}
	else{
		path(x,next[x][y]);
		printf(" %d",next[x][y]);}
}

int main(){

	int n;
	int k;
	int v,w;
	int x,y;
	int cont = 1;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		for(int i = 1; i <= MAX ; i++) 
			for(int j = 1; j <= MAX; j++){
				adj[i][j] = INF; next[i][j] = 0;}
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&k);
			for(int j = 1; j <= k; j++){
				scanf("%d %d",&v,&w);
				adj[i][v] = w;
			}
		}

		for(int i = 1 ; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(adj[i][j] != INF && i!=j) next[i][j] = i;

		scanf("%d %d",&x,&y);
		floyd();
		printf("Case %d: Path =",cont++);
		path(x,y);
		printf(" %d",y);
		printf("; %d second delay\n",adj[x][y]);
	}
	return 0;
}
