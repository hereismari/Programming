#include <bits/stdc++.h>
#define MAX 10001
#define INF 1000000002

using namespace std;

int value[MAX];
vector<int> adj[MAX];

int dijkstra(int i,int x, int n){

	priority_queue< pair<int,int> > fila;
	int dist[MAX];
	for(int j = 0; j < n; j++) dist[j] = INF;
	dist[i] = value[i];
	fila.push(make_pair(dist[i],i));

	while(!fila.empty()){

		int u = fila.top().second;
		int d = fila.top().first;
		fila.pop();

		if(d == dist[u])
			for(int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i];
				int di = value[v];
				if(di + d < dist[v]){
					dist[v] = d + di;
					fila.push(make_pair(dist[v],v));
				}
			}			
	}

	return dist[x];
}	

int main(){

	int n,m,k;
	float  p;
	int x,y;
	int s;

	while(scanf("%d %d %d %f",&n,&m,&k,&p) != EOF){
		for(int i = 0; i <= n; i++){ value[i] = 0; adj[i].clear();}		
		for(int i = 0 ; i < m; i++){
			scanf("%d %d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		scanf("%d",&s);
		for(int i = 0 ; i < s; i++){
			scanf("%d",&x);
			value[x]++;
		}
		scanf("%d %d",&x,&y);
		int min_soldiers = dijkstra(x,y,n+1);
		printf("%.3f\n",k-min_soldiers>=0?pow(p,min_soldiers):0);

	}

	return 0;
}

