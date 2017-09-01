#include <bits/stdc++.h>
#define MAX 602
#define pb push_back

using namespace std;

vector<int> adj[MAX];
int t[MAX], dp[MAX][MAX], n , m, x , y;

int solve(int city, int time) {

    if(time > MAX) return 0;
    if(dp[city][time] != -1) return dp[city][time];

    dp[city][time] = dp[city][time+1];
    for(int i = 0; i < adj[city].size(); i++){
        int v = adj[city][i];
        dp[city][time] = max(dp[city][time], solve(v,time+1));
    }

    if(t[time] == city) dp[city][time] += 1;
    return dp[city][time];
}

int main() {
    int teste = 1;
    while(scanf("%d %d",&n, &m) == 2 && n > 0) {
        
        memset(dp, -1, sizeof dp);
        for(int i = 0; i <= n; i++) adj[i].clear();

        for(int i = 0; i < n-1; i++){
            scanf("%d %d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(int i = 1; i <= m; i++) scanf("%d",&t[i]);
        printf("Teste %d\n", teste++);
        printf("%d\n\n",solve(1,0));
    }
    return 0;
}
