#include <bits/stdc++.h>

#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define MAX 110000
#define ll long long
#define BLACK 0
#define WHITE 1
#define pb push_back

using namespace std;

int n, m, value[MAX], x, y, ans;
vector<int> adj[MAX];
set<int> gcds[MAX];
bool vis[MAX];

void dfs(int node, int g) {
	vis[g] = true;
	gcds[node].insert(g);
	for(int i = 0; i < (int)adj[node].size(); i++){
		int v = adj[node][i];
		int new_g = __gcd(value[v],g);
		if(gcds[v].find(new_g) == gcds[v].end()) dfs(v, new_g);
	}
}

int main() {

	while(scanf("%d %d", &n, &m) != EOF) {
		
		//limpa 
		ans = 0;
		for(int i = 1; i <= n; i++) { adj[i].clear(); gcds[i].clear(); }
		memset(vis, false, sizeof vis);
		
		//entrada
		for(int i = 1; i <= n; i++) scanf("%d", &value[i]);
		
		//monta grafico
		for(int i = 1; i <= m; i++) {
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}

		//resposta :D
		for(int i = 1; i <= n; i++) dfs(i, value[i]);
		for(int i = 1; i < MAX; i++) ans += vis[i];
	
		printf("%d\n", ans);
	}
	
	return 0;
}
