#include <bits/stdc++.h>
#define MAX 100
#define INF 10000000
using namespace std;

vector<int> adj[MAX];
void startAdj(int _size) { for(int i = 1; i <= _size; i++) adj[i].clear();}

void bfs(int x,int y, int n){

	queue<int> fila;
	bool visitado[MAX];
	int dist[MAX];
	for(int i = 1; i <= n ; i++) dist[i] = INF;
	for(int i = 1; i <= n ; i++) visitado[i] = false;
	fila.push(x);
	visitado[x] = true;
	dist[x] = 0;

	while(!fila.empty()){
		int top = fila.front(); fila.pop();
		for(int i = 0; i < adj[top].size(); i++)
			if(!visitado[adj[top][i]])
			{ visitado[adj[top][i]] = true; dist[adj[top][i]] = dist[top] + 1; fila.push(adj[top][i]);}
	}
	for(int i = 1; i <= n; i++){
		if(dist[i] <= y && i!=x)
			printf("%d ",i);
	}
	printf("\n");

}

int main(){
	int c,l,e,p;
	int cont = 1;
	int x,y;
	while(1){
		scanf("%d %d %d %d",&c,&e,&l,&p);
		if(c == 0) break;
		startAdj(c);
		for(int i = 0 ; i < e ;i++){
			scanf("%d %d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		printf("Teste %d\n",cont++);
		bfs(l,p,c);

	}
	return 0;
}
