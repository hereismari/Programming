#include <bits/stdc++.h>
#define MAX 20000
#define pb push_back

using namespace std;

vector<int> adj[MAX];
int n, m, x, a, b, dist[MAX];
int w[MAX];

int ans(int k) {

    if(dist[k] ==-1) {
        dist[k] = 0;
        for(int i = 0; i < adj[k].size(); i++)
            	dist[k] = max(dist[k], ans(adj[k][i]) + 1);
    }
    return dist[k];
}

int main() {

    int teste = 1;
    while(true) {
        memset(dist, -1, sizeof dist);
        scanf("%d %d %d",&n,&m,&x);
        if(n == 0) break;
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
        for(int i = 0; i < m; i++) { scanf("%d %d",&a,&b); if (w[a] > w[b]) adj[a].pb(b); }
        printf("Teste %d\n%d\n\n",teste++,ans(x));
    }
    return 0;
}
