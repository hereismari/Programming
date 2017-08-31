#include <bits/stdc++.h>
#define MAX 100000
#define INF -1
using namespace std;

bool show[MAX];
vector<int> adj[MAX];
void initAdj(int x){ for(int i = 0 ; i < x ; i++) {adj[i].clear(); show[i] = false;} }

int bfs(int x,int y){

	queue<int> fila;
	int dist[MAX];
	bool visit[MAX];

	for(int i = 0 ; i < MAX; i++){ dist[i] = -1; visit[i] = false; }

	fila.push(x);
	dist[x] = 0;
	visit[x] = true;

	while(!fila.empty()){
		int top = fila.front(); fila.pop();
		for(int i = 0 ; i < adj[top].size(); i++)
			if(!visit[adj[top][i]]){
				visit[adj[top][i]] = true;
				dist[adj[top][i]] = dist[top] + 1;
				fila.push(adj[top][i]);
			}
	}
	int cont = 0;
	for(int i = 0 ; i < MAX; i++)
		if(show[i]  && (dist[i] == INF || dist[i] > y))
			cont++;

	return cont;
}

int main(){
	int n;
	int x,y;
	int count = 1;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		initAdj(MAX);
		for(int i = 0; i < n ; i++){
			scanf("%d %d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
			show[x] = true;
			show[y] = true;
		}
		
		while(1){

			scanf("%d %d",&x,&y);
			if(x == 0 && y == 0) break;
			else printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",count++,bfs(x,y),x,y);
		}
	}
	return 0;
}
