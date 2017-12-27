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

#define MAX_E 100010


ll INF = 1000000000000;

int par[MAX], level[MAX], id[MAX], dp[MAX][LOG_MAX];
vector<int> graph[MAX];

// int p[MAX];
//set<int> s[MAX];

// LCA
int build_level(int n, int p) {

  level[n] = level[p] + 1;
  par[n] = p;

  for(int i = 0; i < graph[n].size(); i++) {
    int next = graph[n][i];
    if (level[next] == -1) {
      build_level(next, n);
    }
  }
}


/*
void preprocessing(int n) {

  if(n == 0) return;
  if(p[n] != -1) return;
  
  preprocessing(par[n]);
  
  s[n].insert(s[par[n]].begin(), s[par[n]].end());
  p[n] = 1; 
}*/

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
  
  set<int> res;
  res.insert(id[0]);
  
  int aux = x;
  while(aux != 0) { res.insert(id[aux]); aux = par[aux]; }
  
  aux = y;
  while(aux != 0) { res.insert(id[aux]); aux = par[aux]; }
  
  //res.insert(s[y].begin(), s[y].end());
  
  //int ans_x = nodes[x].turns, ans_y = nodes[y].turns;
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
    //for(auto f : s[y]) if (f != id[y]) res.erase(f);
    
    aux = par[y];
    if(y != 0) res.erase(id[0]);
    while(aux != 0) { res.erase(id[aux]); aux = par[aux]; }
    
    return res.size();
  }
  // otherwise we need to move them up together while they're different
  for(int i = log_x; i >= 0; i--) {
    if(dp[x][i] != -1 && dp[x][i] != dp[y][i]) {
      x = dp[x][i], y = dp[y][i];
    }
  }
  
  //printf(" ** %d %d %d\n", x, y, res.size());
  //for(auto f : s[par[y]]) if (f != id[par[y]]) res.erase(f);
  aux = par[par[y]];
  if(par[y] != 0) res.erase(id[0]);
  while(aux != 0) { res.erase(id[aux]); aux = par[aux]; }
    
  return res.size();
}

int main() {

  int n, m;
  while(scanf("%d %d", &n, &m) != EOF) {
    
    // clean graph
    memset(par, -1, sizeof par);
    //memset(p, -1, sizeof p);
    memset(level, -1, sizeof level);
    
    for(int i = 0; i < n; i++) { 
      graph[i].clear();
    }
    
    int cont = 0;
    map<string, int> m1;
    string s1;
    for(int i = 0; i < n; i++) {
      cin >> s1;
      if(m1.find(s1) == m1.end()) m1[s1] = ++cont;
      id[i] = m1[s1];
     // s[i].insert(id[i]);
    } 
    
    int x, y;
    for(int i = 0; i < n-1; i++) {
      scanf("%d %d", &x, &y);
      x--; y--;
      graph[x].push_back(y);
    }
    
    build_level(0, 0);
    
    calc_dp(n);
    
    /*for(int i = 1; i < n; i++) { 
      preprocessing(i);
      /*printf("set %d\n", i);
      for(auto f : s[i]) {
        printf("%d ", f); 
      }
    }*/
    
    for(int i = 0; i < m; i++) {
      scanf("%d %d", &x, &y);
      x--; y--;
      printf("%d\n", lca(x, y));
    }
    
  }
  
  return 0;
}
