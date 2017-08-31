#include <bits/stdc++.h>

using namespace std;

#define MAX 200100

int a[MAX], id[MAX], color[MAX];
vector<int> adj[MAX];
bool vis[MAX];

int cont, max_cont;

void dfs(int node, int id_) {
    
    vis[node] = true;
    cont++;
    
    if(id[a[node]] == id_) color[a[node]]++;
    else { 
        id[a[node]] = id_;
        color[a[node]] = 1;
    }

    max_cont = max(color[a[node]], max_cont);
    for(int i = 0; i < adj[node].size(); i++) {
        if(!vis[adj[node][i]])
            dfs(adj[node][i], id_);
    }
}

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int x, y;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
    
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    memset(vis, false, sizeof vis);
    memset(color, 0, sizeof color);
    memset(id, 0, sizeof id);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cont = 0, max_cont = 0;
            dfs(i, i);
            ans += cont - max_cont;
        }
    }

    printf("%d\n", ans);

    return 0;
}
