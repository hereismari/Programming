#include <bits/stdc++.h> 

#define MAX 1010
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;
vector<int> adj[MAX][2];
int lvl[MAX], dp[MAX][MAX];
bool vis[MAX];

void bfs() {
    
    memset(vis, false, sizeof vis);
    lvl[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int h = q.front(); q.pop();
        vis[h] = true;
        for(int i = 0; i < adj[h][0].size(); i++) {
            int v = adj[h][0][i];
            if(!vis[v]) {
                lvl[v] = lvl[h] + 1;
                q.push(v);
		vis[v] = true;
            }
        }
    }
}

bool solve(int a, int b) {

    if(dp[a][b] != -1) return dp[a][b];

    int node = lvl[a] > lvl[b] ? a : b;
    int other = node == a ? b : a;

    for(int i = 0; i < adj[node][1].size(); i++){
        int v = adj[node][1][i];
        if(solve(other, v)) return dp[a][b] = dp[b][a] = true;
    }
    return dp[a][b] = dp[b][a] = false;
}

int main() {
 
    while(scanf("%d %d",&n, &m) != EOF){
        
        for(int i = 1; i <= n; i++) { adj[i][0].clear(); adj[i][1].clear(); }
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            adj[x][0].pb(y);
            adj[y][1].pb(x);
        }
        
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; i++) {dp[1][i] = true; dp[i][1] = true;}
        for(int i = 2; i <= n; i++) dp[i][i] = false;
        
        bfs();

        ll ans = 0LL;
        for(int i = 1; i <= n; i++)
            for(int j = i+1; j <= n; j++)
                ans += solve(i,j);
        printf("%lld\n", ans);
    }

	return 0; 
}
