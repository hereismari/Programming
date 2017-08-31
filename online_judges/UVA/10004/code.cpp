#include <bits/stdc++.h>
#define MAX 100000
#define NOT_PAINTED -1
#define BLACK 1
#define WHITE 2

using namespace std;

int m, n;
int x, y;

int color[MAX];
vector<int> adj[MAX];
bool flag;

void clean() {

	for(int i = 0 ; i <= m; i++)
	{
		adj[i].clear(); color[i] = NOT_PAINTED;
	}

}

void bfs(int x, int col) {

	queue<int> q;
	q.push(x);
	color[x] = col;

	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int i = 0 ; i < adj[top].size(); i++){
			if(color[adj[top][i]] == NOT_PAINTED)
			{
				q.push(adj[top][i]);
				color[adj[top][i]] = (color[top] == BLACK) ? WHITE : BLACK;
			}
			else if(color[adj[top][i]] == color[top]) flag = false;
		}
	}
}


int main() {

	while(true){
	
		scanf("%d",&m); if(m == 0) break;
		scanf("%d",&n);
		clean();

		for(int i = 0 ; i < n; i++){
			scanf("%d %d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		flag = true;
		for(int i = 0; i < m; i++){
			if(color[i] == NOT_PAINTED){
				bfs(i,BLACK);
			}
		}

		printf("%s",!flag?"NOT BICOLORABLE.\n":"BICOLORABLE.\n");
		
	}


	return 0;
}
