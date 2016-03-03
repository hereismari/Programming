#include <bits/stdc++.h>
#define MAX 900010
#define INF 2*1000000000

using namespace std;

struct data{

	int id;
	int b;
	int w;

	data(int id, int b, int w){
		this->id = id;
		this->b = b;
		this->w = w;
	}
};

vector<data> adj[MAX];
int usedEdge[MAX]; 

void dijkstra(int x){

	int dist[MAX];
	for(int j = 0 ; j < MAX; j++) {dist[j] = INF; usedEdge[MAX] = 0;}
	priority_queue< pair<int,int> > fila;

	fila.push(make_pair(0,x));
	dist[x] = 0;
	
	while(!fila.empty()) {
		
		pair<int,int> top = fila.top(); fila.pop();
		int u = top.second;
		int d = top.first;

		for(int i = 0 ; i < adj[u].size(); i++){
			
			int v = adj[u][i].b;
			int weight = adj[u][i].w;
			int id = adj[u][i].id;

			if(dist[u] + weight <= dist[v]){
				dist[v] = dist[u] + weight;
				usedEdge[v] = id;
				fila.push(make_pair(dist[v],v));
			}
		}
	}
}

int main(){

	int n;
	int m;
	int x,y,w;

	scanf("%d %d",&n,&m);

	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&x,&y,&w);
		adj[x].push_back(data(i+1,y,w));
		adj[y].push_back(data(i+1,x,w));
	}

	scanf("%d",&x);
	dijkstra(x);

	int answer = 0;
	for(int i = 1; i <= n; i++)
		if(usedEdge[i] != 0)
			answer += 1;

	printf("%d\n",answer);
	for(int i = 1; i <= n; i++)
		if(usedEdge[i] != 0)
				printf("%d ", usedEdge[i]);
	
	return 0;
}
