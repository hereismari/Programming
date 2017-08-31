#include <bits/stdc++.h>

#define MAX 120000
#define pb push_back

using namespace std;

int n, m, x, y;
int c[MAX];
vector<int> adj[MAX];

int dfs(int k, int cats, int par){
    
    int ans = 0;
    if(cats > m) return 0;
    if(adj[k].size() == 1 && par !=-1) ans = 1;

    for(int i = 0; i < adj[k].size(); i++){
        int v = adj[k][i];
        if(v != par) ans += dfs(v, c[v] ? cats + 1 : 0, k); 
    }

    return ans;
}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    printf("%d\n", dfs(1,c[1], -1));
    return 0;
}
