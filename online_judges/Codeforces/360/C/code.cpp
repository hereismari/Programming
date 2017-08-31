#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MAX 100100

int n, m;
vector<int> adj[MAX];
vector<int> g1, g2;
bool flag;

int color[MAX];

void dfs(int i, int c = 1) {
   
    if(c == 1) g1.pb(i);
    else g2.pb(i);

    color[i] = c;

    for(int j = 0; j < adj[i].size(); j++) {
        int v = adj[i][j];
        if(color[v] == c) { flag = true; break; }
        else if(color[v]) continue;
        else dfs(v, c == 1 ? 2 : 1);
    }

}

int main() {

    memset(color, 0, sizeof color);
    flag = false;

    scanf("%d %d", &n, &m);

    int x, y;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }


    int c = 1;
    for(int i = 1; i <= n; i++) {
        if(!color[i]) dfs(i, c == 1 ? c = 2 : c = 1);
    }

    if(flag) { printf("-1\n"); return 0; }

    printf("%d\n", g1.size());
    for(int i = 0 ; i < g1.size(); i++)
        printf("%d ", g1[i]);
    
    printf("\n%d\n", g2.size());
     for(int i = 0 ; i < g2.size(); i++)
        printf("%d ", g2[i]);
    
    return 0;
}
