#include <bits/stdc++.h> 

#define MAX 1011 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
#define BLACK 1
#define WHITE 0

using namespace std; 

int n, m, x, y;
int adj[MAX][MAX], dp[MAX][2];
bool vis[MAX];

int ans(int node, int p) {

    if(dp[node][p] != -1) return dp[node][p];
    vis[node] = true;
    
    int res = p;

    for(int i = 1; i <= n; i++){
        if(p && adj[node][i] > 0 && !vis[i]) {
            res += min(ans(i, 0), ans(i, 1));
        }
        else if(adj[node][i] > 0 && !vis[i]){
            res += ans(i,1);
        }
    }
    
    vis[node] = false;
    return dp[node][p] = res;
}

int main() {
 
    while(scanf("%d",&n) && n != 0){

       memset(adj, 0, sizeof adj);
       for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            for(int j = 0; j < x; j++){
                scanf("%d", &y);
                adj[i][y] = 1;
           }
        }

        memset(dp, -1, sizeof dp);
        memset(vis, false, sizeof vis);
        vis[1] = true;
        printf("%d\n", max(1, min(ans(1, 0), ans(1, 1))));
    }

	return 0; 
}
