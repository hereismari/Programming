#include <bits/stdc++.h>
#define MAX 10000
#define INF 2*1000000000

using namespace std;

int dp[MAX][MAX];
vector < pair < int, int > >  adj[MAX];
int n;

int bfs(int i, int y){
	
	int dist[MAX] = {INF};
	for(int j = 0 ; j < MAX; j++) dist[j] = INF;
	priority_queue< pair<int,int> > fila;

	fila.push(make_pair(0,i));
	dist[i] = 0;

	while(!fila.empty()){
		pair<int,int> k = fila.top(); fila.pop();
		int d = k.first;
		int u = k.second;
//		printf("%d %d\n",dist[u],d);
		if(d == dist[u])
			for(int j = 0 ; j < adj[u].size() ; j++)
			{
				int v = adj[u][j].first;
				int weight = adj[u][j].second;
//				printf("%d %d\n",dist[u] + weight,dist[v]);
				if(dist[u] + weight < dist[v]){
					dist[v] = dist[u] + weight;
					fila.push(make_pair(dist[v],v));
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
		
		scanf("%d %d",&n,&m);		
		if(n == 0 && m == 0) break;
		if(cont++ > 0) printf("\n");		
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++) adj[i].clear();
		for(int i = 0 ; i < m; i++){
			scanf("%d %d %d",&x,&y,&d);
			if(dp[y][x] != 0)
			{
				dp[x][y] = 0;
				dp[y][x] = 0;
				for(int j = 0; j < adj[y].size(); j++)
					if(adj[y][j].first == x){ adj[y][j].second = 0; break;}
				adj[x].push_back(make_pair(y,0));
			}
			else {dp[x][y] = d; adj[x].push_back(make_pair(y,d));}
		}
		scanf("%d",&k);
		for(int i = 0 ; i < k; i++)
		{
			scanf("%d %d",&x,&y);
			int res = bfs(x,y);
			if(res >= 0) printf("%d\n",res);
			else printf("Nao e possivel entregar a carta\n");
		}
	
	}
	return 0;
}
