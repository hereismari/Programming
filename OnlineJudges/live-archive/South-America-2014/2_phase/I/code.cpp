#include <bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MAX 2000000
#define pb push_back

using namespace std;

vector<pii> g[MAX];
int f[MAX], ans1 = 0, ans2 = 0;

void dfs(int u, int &friends, int dist) {
    int v, ff = 0, cost;
    friends = f[u];
    if (f[u]) ans1 = max(ans1, dist);
    for (int i = 0; i < g[u].size(); i++) {
        v = g[u][i].first;
        dfs(v, ff, dist + g[u][i].second);
        if (ff > 0) {
            w += g[u][i].second;
            friends += ff;
        }
    }
}

int main() {
    int n, m, x, y, v;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) g[i].clear(), f[i] = 0;
        for (int i = 1; i < n; i++) scanf("%d %d %d", &x, &y, &v), g[x].pb(mp(y, v));
        for (int i = 0; i < m; i++) scanf("%d", &x), f[x] = 1;
        ans1 = 0, ans2 = 0;
        dfs(1, x, 0);
        printf("%d\n", ans1 - ans2);
    }
    return 0;
}
