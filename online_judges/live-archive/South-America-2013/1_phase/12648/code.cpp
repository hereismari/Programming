#include <bits/stdc++.h>
#define MAX 1000
#define pb push_back

using namespace std;

int n, m, k, x, y;
int age[MAX],id[MAX];
char c;
bool visited[MAX];
vector<int> parent[MAX], adj[MAX];

void dfs(int v, int par) {
    visited[v] = true; parent[par].push_back(v);
    for(int i = 0; i < adj[v].size(); i++)
        if(!visited[adj[v][i]])
            dfs(adj[v][i],par);
}

int main() {

    while(scanf("%d %d %d",&n, &m, &k) != EOF) {
        
        for(int i = 1; i <= n; i++){
            scanf("%d",&age[i]);
            id[i] = i;
            adj[i].clear();
            parent[i].clear();
        }

        for(int i = 1; i <= m; i++){
            scanf("%d %d",&x,&y);
            adj[y].pb(x);
        }

        for(int i = 1; i <= n; i++){
            memset(visited, false, sizeof visited);
            visited[i] = true;
            for(int j = 0; j < adj[i].size(); j++)
                if(!visited[adj[i][j]])
                    dfs(adj[i][j],i);
        }

        for(int i = 0; i < k; i++){
            scanf("\n%c",&c);
            if(c == 'P'){
                scanf("%d",&x);
                int ans = 1000;
                int aux = id[x];
                for(int i = 0; i < parent[aux].size(); i++)
                    ans = min(ans, age[parent[aux][i]]);
                if(ans == 1000) printf("*\n");
                else printf("%d\n", ans);
            }
            else {
                scanf("%d %d",&x,&y);
                swap(age[id[x]],age[id[y]]);
                swap(id[x],id[y]);
            }
       }

    }

    return 0;
}
