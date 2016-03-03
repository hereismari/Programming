#include <bits/stdc++.h>
#define MAX 5010

using namespace std;

int n, m, level[MAX], adj[MAX][MAX];
int x, y;

int main() {

	scanf("%d %d", &n, &m);

	memset(level, 0 , sizeof level);
	memset(adj, false, sizeof adj);

	for(int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		adj[x][y] = adj[y][x] = true;
		level[x]++; level[y]++;
	} 

	int ans = INT_MAX;
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++)
			if(adj[i][j])
				for(int k = j+1; k <= n; k++)
					if(adj[i][k] && adj[j][k])
						ans = min(ans, level[i] + level[j] + level[k]);
	}

	if(ans == INT_MAX) printf("-1\n");
	else printf("%d\n",ans-6);
	return 0;
}

