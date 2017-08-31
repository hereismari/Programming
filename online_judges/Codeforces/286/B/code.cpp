#include <bits/stdc++.h>
#define p pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAX 102
using namespace std;

int n, m;
int x, y, c, k;
vector<p> adj[MAX];
int answer;
bool visited[MAX];
bool color_used[MAX];

void dfs(int a, int b, int color){

	visited[a] = true;
	for(int i = 0 ; i < adj[a].size(); i++){
		if(adj[a][i].F == b && adj[a][i].S == color && !color_used[color]){
			answer += 1;
			color_used[color] = true;
			return;
		}
		else if(!visited[adj[a][i].F] && adj[a][i].S == color)
			dfs(adj[a][i].F,b,color);
		
	}
}


void dfs_aux(int a, int b){
	answer = 0;
	memset(color_used,false,sizeof(color_used));
	for(int i = 1; i <= m ; i++){
		memset(visited,false,sizeof(visited));
		dfs(a,b,i); 	
	}
}
int main() {

	scanf("%d %d",&n,&m);

	for(int i = 0 ; i < m; i++){
		scanf("%d %d %d",&x,&y,&c);
		adj[x].push_back(mp(y,c));
		adj[y].push_back(mp(x,c));
	}

	scanf("%d",&k);
	for(int i = 0; i < k; i++){
		scanf("%d %d",&x,&y);
		dfs_aux(x,y);
		printf("%d\n",answer);
	}

	return 0;
}
