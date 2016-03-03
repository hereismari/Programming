#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int n,m,x;
vector<int> graph[MAX];
bool visited[MAX];

int cont[MAX];
int cont_visited[MAX];

void bfs() {

	queue<int> q;
	q.push(0);
	int dist[MAX];
	dist[0] = 0;
	int top = 0;	
	while(!q.empty()){
		top = q.front(); q.pop();
		for(int i = 0 ; i < graph[top].size(); i++){
			dist[graph[top][i]] = dist[top] + 1;
			cont[dist[top] + 1]++;
			if(visited[graph[top][i]])
				cont_visited[dist[top] + 1]++;			
			q.push(graph[top][i]);
		}
	}

	for(int i = 1; i <= dist[top]; i++){
		printf("%.2f ",cont_visited[i]/(cont[i] * 1.0)*100);
	}
	printf("\n");
}

int main(){

	scanf("%d %d",&n,&m);
	memset(cont,0,sizeof(cont));
	memset(cont_visited,0,sizeof(cont));

	for(int i = 1; i <= n; i++){
		scanf("%d",&x);
		graph[x].push_back(i);
	}	

	for(int i = 1; i <= m; i++){
		scanf("%d",&x);
		visited[x] = true;
	}

	bfs();
	return 0;
}
