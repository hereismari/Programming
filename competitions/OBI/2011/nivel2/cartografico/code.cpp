#include <bits/stdc++.h>
#define MAX 1000003

using namespace std;

vector < vector<int> > adj(MAX);

int x,y;

int bfs1(int i){

	queue<int> fila;
	bool visitados[MAX] = {false};
	int level[MAX];
	fila.push(i);
	level[i] = 0;
	int k;
	while(!fila.empty()){
		k = fila.front();
		visitados[k] = true;
//		printf("%d %d\n",1,k);
		for(int j = 0 ; j < adj[k].size(); j++)
			if(!visitados[adj[k][j]]){
				fila.push(adj[k][j]);
				level[adj[k][j]] = level[k] + 1;
			}
		fila.pop();
	}
	return k;
}

int bfs2(int i){

	bool visitados[MAX] = {false};
	int level[MAX];
	queue<int> fila;
	fila.push(i);
	level[i] = 0;
	int k;
	while(!fila.empty()){
		k = fila.front();
//		printf("%d %d\n",2,k);
		visitados[k] = true;
		for(int j = 0 ; j < adj[k].size(); j++)
			if(!visitados[adj[k][j]]){
				fila.push(adj[k][j]);
				level[adj[k][j]] = level[k] + 1;
			}
		fila.pop();
	}
	return level[k];
}
int main(){

	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++){
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	printf("%d\n",bfs2(bfs1(x)));
	return 0;
}
