#include <bits/stdc++.h>
#define MAX 1000
#define INF 2*1000000

using namespace std;

int adj[MAX][MAX];

int bfs(int i, int y, int a){
	
	int dist[MAX];	
	for(int j = 0 ; j <= a; j++) dist[j] = INF;
	priority_queue< pair<int,int> > fila;

	fila.push(make_pair(0,i));
	dist[i] = 0;

	while(!fila.empty()){
		pair<int,int> k = fila.top(); fila.pop();
		int d = k.first;
		int u = k.second;
//		printf("%d %d\n",dist[u],d);
		if(d == dist[u]){
			for(int j = 1; j <= a ; j++)
			{
//				printf("%d ",adj[u][j]);
				if(adj[u][j] != INF){
					int v = j;
					int weight = adj[u][v];
//					printf("%d %d\n",dist[u] + weight,dist[v]);
					if(dist[u] + weight < dist[v]){
						dist[v] = dist[u] + weight;
						fila.push(make_pair(dist[v],v));
					}
				}
			}
		}
	}
	return dist[y] != INF ? dist[y]: -1;
}

int main(){

	int cont = 0;
	int n,m;
	int x,y,d;
	int k;

	while(1){
		
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		if(cont++ > 0) cout << "\n";		

		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++) 
				adj[i][j] = INF;

		for(int i = 0 ; i < m; i++){
			cin >> x >> y >> d;
			if(adj[y][x] != INF)
			{
				adj[x][y] = 0;
				adj[y][x] = 0;
				
			}
			else adj[x][y] = d;
		}
		cin >> k;
		for(int i = 0 ; i < k; i++)
		{
			cin >> x >> y;
			int res = bfs(x,y,n);
			if(res >= 0) cout << res << "\n";
			else cout << "Nao e possivel entregar a carta\n";
		}
	
	}
	return 0;
}
