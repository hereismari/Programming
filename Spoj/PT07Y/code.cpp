#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
bool answer;

void dfs(int x, int par){
	
	visited[x] = true;
	for(int i = 0 ; i < adj[x].size(); i++){
		if(!visited[adj[x][i]])
			dfs(adj[x][i],x);
		else if(par != adj[x][i]) answer = false;
		
	}
}

int main() {
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i = 0 ; i < m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		
	}

	answer = true;	
	dfs(1,1);
	
	for(int i = 1; i <= n; i++)
		if(!visited[i]) answer = false;
	
	printf("%s",answer?"YES\n":"NO\n");
	return 0;
}
