#include <bits/stdc++.h>

using namespace std;

#define MAX 500100
#define LOG_MAX 20
#define ll long long int
#define vi vector<int>
#define mp make_pair
#define F first
#define S second
#define pb push_back

#define MAX_E 300010

ll INF = 1000000000000;

int par[MAX], level[MAX], dp[MAX][LOG_MAX];
ll max_dp[MAX][LOG_MAX];
vector<pair<int, ll> > graph[MAX];

ll dist[MAX];

// KRUSKAL
struct edge { 
  int from, to;
  ll weight;

  edge(int from = -1, int to = -1, ll weight = -1L) {
    this->from = from;
    this->to = to;
    this->weight = weight;
  }

  bool operator < (const edge &o) const {
    return weight > o.weight;
  }
};

struct unionFind {

  vi p, rank; // remember: vi is vector<int>

  unionFind(int N) { 
    rank.assign(N, 0); p.assign(N, 0); 
    for (int i = 0; i < N; i++) p[i] = i; 
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; 
    }
  } 
};

edge e[MAX_E];

void kruskal(int vertices, int edges) {

	sort(e, e + edges);

  unionFind u = unionFind(vertices + 1);

  for(int i = 0; i < edges; i++) {
      if(!u.isSameSet(e[i].to, e[i].from)) {
      
          //printf("** %d %d %lld\n", e[i].to, e[i].from, e[i].weight);
      
          graph[e[i].from].pb(mp(e[i].to, e[i].weight));
          graph[e[i].to].pb(mp(e[i].from, e[i].weight));

          u.unionSet(e[i].to, e[i].from);
      }
  }
}

// LCA

int build_level(int n, int p, ll w) {
  
  if(n != 1) {
    level[n] = level[p] + 1;
    par[n] = p;
    dist[n] = w; 
  }
//  printf("level %d = %d\n", n, level[n]);

  for(int i = 0; i < graph[n].size(); i++) {
    int next = graph[n][i].F;
    if (level[next] == -1) {
      build_level(next, n, graph[n][i].S);
    }
  }
}

void calc_dp(int n) {

  memset(dp, -1, sizeof dp);
  
  for(int i = 1; i <= n; i++) {
  
    for(int j = 0; j < LOG_MAX; j++) max_dp[i][j] = INF;
  
    dp[i][0] = par[i];
    max_dp[i][0] = dist[i];
    if(i == 1) max_dp[i][0] = INF;
  }

  for(int i = 1; (1 << i) <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(dp[j][i-1] != -1) {
        dp[j][i] = dp[dp[j][i-1]][i-1];
        max_dp[j][i]  = min(max_dp[j][i-1], max_dp[dp[j][i-1]][i-1]);
        //printf("dp[%d][%d] = %d\n", j, i, dp[j][i]);
        //printf("max_dp[%d][%d] = %lld\n", j, i, max_dp[j][i]);
      }
      //printf("dp[%d][%d] = %d\n", j, i, dp[j][i]);
    }
  }
}

ll lca(int x, int y) {

  ll res = INF;
  
  // calculate log of level of x
  int log_x;
  for(log_x = 1; (1 << log_x) <= level[x]; log_x++);
  log_x--;
  
  // move x to the same level of y
  for(int i = log_x; i >= 0; i--) {
    if(level[x] - (1 << i) >= level[y]) {
      res = min(res, max_dp[x][i]);
      x = dp[x][i];
    }
  }
  
  // if they're equal, we're done
  if(x == y) return res;
  
  // otherwise we need to move them up together while they're different
  for(int i = log_x; i >= 0; i--) {
    if(dp[x][i] != -1 && dp[x][i] != dp[y][i]) {
      res = min(res, max_dp[x][i]);
      res = min(res, max_dp[y][i]);
      x = dp[x][i], y = dp[y][i];
    }
  }
  
  res = min(max_dp[x][0], res);
  res = min(res, max_dp[y][0]);
  
  return res;
}

int main() {

  int n, m, s;
  while(scanf("%d %d %d", &n, &m, &s) != EOF) {
    
    // clean graph
    memset(par, -1, sizeof par);
    memset(level, -1, sizeof level);
    memset(dist, 0, sizeof dist);
    
    for(int i = 1; i <= n; i++) { 
      graph[i].clear();
    }
    
    int x, y;
    ll v;
    for(int j = 0; j < m; j++) {
      scanf("%d %d %lld", &x, &y, &v);
      e[j] = edge(x, y, v);
    }
    
    kruskal(n, m);
    
    // build level
    level[1] = 0;
    par[1] = 1;
    build_level(1, 1, 0);
    
    // calculate dp
    calc_dp(n);
    
    for(int j = 0; j < s; j++) {
      scanf("%d %d", &x, &y);
      
      // level of x must be >= than level of y
      if (level[x] < level[y]) {
        int aux = x; x = y; y = aux;
      }
      
      printf("%lld\n", lca(x, y));
    }
    
  }
  
  return 0;
}
