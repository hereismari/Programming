#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
#define LOG_MAX 50

int par[MAX], level[MAX], dp[MAX][LOG_MAX];

int build_level(int n) {
  //printf("%d\n", n);
  if(level[n] == -1) level[n] = 1 + build_level(par[n]);
  else return level[n];
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

  int t;
  scanf("%d", &t);
  
  for(int i = 1; i <= t; i++) {
  
    // clean graph
    memset(par, -1, sizeof par);
    memset(level, -1, sizeof level);
    
    // get graph from input
    int n;
    scanf("%d", &n);

    int m, x, y;
    for(int j = 1; j <= n; j++) {
      scanf("%d", &m);
      for(int k = 0; k < m; k++) {
        scanf("%d", &x);
        par[x] = j;
      }
    }
    
    // find root
    for(int j = 1; j <= n; j++) {
      if(par[j] == -1)
        level[j] = 0;
    }
    
    // build level
    for(int j = 1; j <= n; j++) {
      build_level(j);
    }
    
    // calculate dp
    calc_dp(n);
    
    printf("Case %d:\n", i);
    
    int q;
    scanf("%d", &q);
    
    for(int j = 0; j < q; j++) {
      scanf("%d %d", &x, &y);
      printf("%d\n", lca(x, y));
    }
  }

  return 0;
}
