#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
#define LOG_MAX 20
#define ll long long int

int par[MAX], level[MAX], dp[MAX][LOG_MAX];
vector<int> graph[MAX];

ll dist[MAX];

int build_level(int n) {
  level[n] = level[par[n]] + 1;
  dist[n] = dist[n] + dist[par[n]];
  for(int i = 0; i < graph[n].size(); i++) {
    int next = graph[n][i];
    if (level[next] == -1) build_level(next);
  }
}

void calc_dp(int n) {
  memset(dp, -1, sizeof dp);
  
  for(int i = 1; i <= n; i++) dp[i][0] = par[i];

  for(int i = 1; (1 << i) <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(dp[j][i-1] != -1)
        dp[j][i] = dp[dp[j][i-1]][i-1];
      
      //printf("dp[%d][%d] = %d\n", j, i, dp[j][i]);
    }
  }
}

int lca(int x, int y) {
  
  // level of x must be >= than level of y
  if (level[x] < level[y]) {
    int aux = x; x = y; y = aux;
  }
  
  // calculate log of level of x
  int log_x;
  for(log_x = 1; (1 << log_x) <= level[x]; log_x++);
  log_x--;
  
  
  // move x to the same level of y
  for(int i = log_x; i >= 0; i--) {
    if(level[x] - (1 << i) >= level[y]) {
      x = dp[x][i];
    }
  }
  
  // if they're equal, we're done
  if(x == y) return x;
  
  // otherwise we need to move them up together while they're different
  for(int i = log_x; i >= 0; i--) {
    if(dp[x][i] != -1 && dp[x][i] != dp[y][i]) {
      x = dp[x][i], y = dp[y][i];
    }
  }
  
  return par[x];
}


int main() {

  while(true) {
    
    // get graph from input
    int n;
    scanf("%d", &n);
    if(n == 0) break;
    
    // clean graph
    memset(par, -1, sizeof par);
    memset(level, -1, sizeof level);
    memset(dist, 0, sizeof dist);
    
    for(int i = 0; i <= n; i++) graph[i].clear();

    int x, y;
    ll v;
    for(int j = 1; j <= n-1; j++) {
      scanf("%d %lld", &x, &v);
      par[j] = x;
      graph[x].push_back(j);
      dist[j] = v;
    }
    
    // build level
    level[0] = 0;
    build_level(0);
    
    // calculate dp
    calc_dp(n);
    
    int q;
    scanf("%d", &q);
    
    for(int j = 0; j < q; j++) {
      scanf("%d %d", &x, &y);
      int l = lca(x, y);
      
      ll res = dist[x] + dist[y] - 2 * dist[l];
      printf("%lld ", res);
    }
    
    printf("\n");
  }
  return 0;
}
