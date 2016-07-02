#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 100100  
#define INF 1000000000

int n, m, x, y;
vector<int> adj[MAX];
bool vis[MAX];
bool flag;

void dfs(int index, int par = -1) {

    vis[index] = true;
    for(int i = 0; i < adj[index].size(); i++)
        if(!vis[adj[index][i]]) dfs(adj[index][i], index);
        else if(par != adj[index][i]) flag = false;
}

int main() {
 
    while(scanf("%d %d", &n, &m) != EOF) {

        memset(vis, false, sizeof vis);

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            adj[x].pb(y); adj[y].pb(x);
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            flag = true;
            if(!vis[i]) { dfs(i); ans += flag; }
        }

        printf("%d\n", ans);

    }

	return 0; 
}
