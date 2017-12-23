#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
#define LOG_MAX 20
#define ll long long int
#define vi vector<int>
#define mp make_pair
#define F first
#define S second
#define pb push_back

#define MAX_E 300010

#define LEFT 1
#define DOWN 0
#define RIGHT -1
#define UP 2

ll INF = 1000000000000;

int par[MAX], level[MAX], dp[MAX][LOG_MAX];
vector<int> graph[MAX];

struct node { 
  int id, row, col, dir, turns;
};

node nodes[MAX];

// LCA
int first_non_zero;
int build_level(int n, int p) {
  
  if(n != first_non_zero) {
    level[n] = level[p] + 1;
    par[n] = p;
 
    int p_p = par[p];
    
    nodes[n].turns = nodes[p].turns;
    if(!((nodes[p_p].row == nodes[p].row && nodes[p].row == nodes[n].row) || (nodes[p_p].col == nodes[p].col && nodes[p].col == nodes[n].col)))
      nodes[n].turns++;
  }
  
  //printf("par: %d\n", par[n]);
  //printf("node[%d]\nrow: %d, col: %d, turns: %d\n", n, nodes[n].row,nodes[n].col, nodes[n].turns);

  for(int i = 0; i < graph[n].size(); i++) {
    int next = graph[n][i];
    if (level[next] == -1) {
      build_level(next, n);
    }
  }
}

void calc_dp(int n) {

  memset(dp, -1, sizeof dp);
  for(int i = 0; i < n; i++) dp[i][0] = par[i];

  for(int i = 1; (1 << i) <= n; i++) {
    for(int j = 0; j < n; j++) {
      if(dp[j][i-1] != -1) {
        dp[j][i] = dp[dp[j][i-1]][i-1];
      }
      //printf("dp[%d][%d] = %d\n", j, i, dp[j][i]);
    }
  }
}

int lca(int x, int y) {

  int tmp, log, i;
  if (level[x] < level[y])
    tmp = x, x = y, y = tmp;
  int ans_x = nodes[x].turns, ans_y = nodes[y].turns;
  //printf("%d: %d %d: %d\n", x, level[x], y, level[y]);
  
  // calculate log of level of x
  int log_x;
  for(log_x = 1; (1 << log_x) <= level[x]; log_x++);
  log_x--;
  
  
  int prev_x = x;
  // move x to the same level of y
  for(int i = log_x; i >= 0; i--) {
    if(level[x] - (1 << i) >= level[y]) {
      x = dp[x][i];
    }
    if(level[prev_x] - (1 << i) >= level[y] + 1) {
      prev_x = dp[prev_x][i];
    }
  }
  
  // if they're equal, we're done
  //printf("%d: %d %d: %d %d: %d\n", x, level[x], prev_x, level[prev_x], y, level[y]);
  if(x == y) { 
    int ans = ans_x - nodes[prev_x].turns;
    return ans;
  }
  // otherwise we need to move them up together while they're different
  for(int i = log_x; i >= 0; i--) {
    if(dp[x][i] != -1 && dp[x][i] != dp[y][i]) {
      x = dp[x][i], y = dp[y][i];
    }
  }
  
  // sum[x]-sum[x']+sum[y]-sum[y']+IsTurn(x',z,y').
  //int ans = ans_x + ans_y - nodes[par[x]].turns * 2);
  int ans = ans_x - nodes[x].turns + ans_y - nodes[y].turns + 1;
  //printf("%d: %d - %d %d - %d + 1\n", ans, ans_x, nodes[x].turns, ans_y, nodes[y].turns);
  if((nodes[x].row == nodes[par[x]].row && nodes[y].row == nodes[par[y]].row) || (nodes[x].col == nodes[par[x]].col && nodes[y].col == nodes[par[y]].col)) ans--;
  return ans;
}

int main() {

  int n, m;
  while(scanf("%d %d", &n, &m) != EOF) {
    
    // clean graph
    memset(par, -1, sizeof par);
    memset(level, -1, sizeof level);
    
    for(int i = 0; i <= n * m; i++) { 
      graph[i].clear();
    }
    
    char matrix[n][m];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        scanf("\n%c", &matrix[i][j]);
      }
    }
    
    first_non_zero = -1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(matrix[i][j] == '#') {
          
          int id = i * m + j;
          nodes[id].row = i;
          nodes[id].col = j;
          
          if(first_non_zero == -1) first_non_zero = id;
          if(i+1 < n && matrix[i+1][j] == '#') {
            int new_id = (i+1) * m + j;
            graph[id].pb(new_id);
            graph[new_id].pb(id);
          }
          if(j+1 < n && matrix[i][j+1] == '#') {
            int new_id = i * m + j + 1;
            graph[id].pb(new_id);
            graph[new_id].pb(id);
          }
        }
      }
    }
    
    // build level
    level[first_non_zero] = 0;
    nodes[first_non_zero].turns = 0;
    nodes[first_non_zero].dir = DOWN;
    par[first_non_zero] = first_non_zero;
    build_level(first_non_zero, first_non_zero);
    
    calc_dp(n * m);
    
    int q;
    scanf("%d", &q);
    int x1, y1, x2, y2;
    
    for(int i = 0; i < q; i++) {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      x1--; y1--; x2--; y2--;
      int index1 = x1 * m + y1, index2 = x2 * m + y2;
      printf("%d\n", lca(index1, index2));
    }
    
  }
  
  return 0;
}
