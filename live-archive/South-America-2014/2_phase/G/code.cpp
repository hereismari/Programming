#include <bits/stdc++.h>

#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define MAX 60000
#define ll long long
#define BLACK 0
#define WHITE 1
#define pb push_back

using namespace std;

int n, x[MAX], y[MAX], ans, black, white;
map<pii, int> m;
vector<int> adj[MAX];
bool vis[MAX];

ll dist(int x1, int y1, int x2, int y2) { return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);}

void verify(int x1, int y1, int index) {
	
	for(int i = -5; i < 5; i++){
		for(int j = -5; j < 5; j++){
				if(i == 0 && j == 0) continue;
				pii p2 = mp(x1 + i, y1 + j);
				if(dist(x1 + i, y1 + j, x1, y1) <= 25 && m.count(p2) != 0) {
					adj[index].pb(m[p2]);
					adj[m[p2]].pb(index);
				} 
		}
	}
}

void dfs(int node, int color) {
	
	vis[node] = true;
	if(color == BLACK) { black++; color = WHITE;}
	else { white++; color = BLACK;}
	for(int i = 0; i < (int)adj[node].size(); i++){
		int v = adj[node][i];
		if(!vis[v])
			dfs(v, color);
	}
}

int main() {

	while(scanf("%d", &n) != EOF) {
		
		
		//limpa 
		ans = 0;
		m.clear();
		for(int i = 1; i <= n; i++) adj[i].clear();
		memset(vis, false, sizeof vis);
		
		//entrada
		for(int i = 1; i <= n; i++){
			scanf("%d %d", &x[i], &y[i]);
			m[mp(x[i],y[i])] = i;
		}

		//monta grafico
		for(int i = 1; i <= n; i++) {
			verify(x[i], y[i], i);
		}

		//resposta :D
		for(int i = 1; i <= n; i++) {
			black = white = 0;
			if(!vis[i]) dfs(i, BLACK);
			ans += min(black, white);
		}
	
		printf("%d\n", ans);
	}
	
	return 0;
}
