#include <bits/stdc++.h>
#define MAX 500100

using namespace std;
int x,y;
vector< int > adj[MAX];
bool visited[MAX];

void dfs(int x){
	visited[x] = true;
	for(int i = 0; i < adj[x].size(); i++)
		if(!visited[adj[x][i]])
			dfs(adj[x][i]);	
}

int main() {

	int n,m;
	int answer = 0;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m ; i++){
		scanf("%d %d",&x,&y);	
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 1; i <= n; i++)
		if(!visited[i]){
			answer++; dfs(i);
		}

	printf("%d\n",answer);
	return 0;
}
