#include <bits/stdc++.h>

using namespace std;

#define MAX 50010
#define LOG_MAX 20
#define ll long long int
#define vi vector<int>
#define mp make_pair
#define F first
#define S second
#define pb push_back

#define MAX_E 300010

ll INF = 1e11;

int par[MAX], level[MAX], dp[MAX][LOG_MAX];
vector<pair<int, int> > graph[MAX];

ll dist[MAX];

set<int> pos[MAX];
vector<int> a;

// SEG TREE
struct data {
	ll value;
};

data seg_tree[4*MAX_E];

data make_data(ll value){
	data result;
	result.value = value;
	return result;
};

data combine(data l, data r) {
	data result;
	result.value = min(l.value, r.value);
	return result;
}

void build(int id, int b, int e){

	if(b == e) { 
	//printf("seg_tree[%d] = %d, %d, %d\n", id, dist[a[b-1]], a[b-1], b-1);
	seg_tree[id] = make_data(dist[a[b-1]]); return;}

	int m = (b+e)/2;

	build(2*id, b, m);
	build(2*id + 1, m + 1, e);

	seg_tree[id] = combine(seg_tree[2*id], seg_tree[2*id + 1]);
};

void update(int id, int b, int e, int pos, ll value){

	if(b == e) { seg_tree[id] = make_data(value); return; }

	int m = (b+e)/2;

	if(pos <= m) update(2*id, b, m, pos, value);
	else update(2*id + 1, m+1, e, pos, value);
	
	seg_tree[id] = combine(seg_tree[2*id], seg_tree[2*id + 1]);

}

data query(int id, int b, int e, int i, int j) {

  //printf("%d %d %d %d %d\n", id, b, e, i ,j);
  if(i > j) return make_data(INF);

	if(i == b && j == e) return seg_tree[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id, b, m, i, j);
	if(i > m) return query(2*id+1, m+1, e, i, j);
	return combine(query(2*id, b, m, i, m), query(2*id+1, m+1, e, m+1, j));
};

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
  
  a.push_back(n);
  
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
      a.push_back(n);
    }
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

int get_lower_bound(int x, int l) {
  set<int>::iterator it = pos[l].lower_bound(x);
  if (it != pos[l].begin()) it--;
  return *it;
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
      pos[i].clear();
    }
    
    a.clear();
    
    int x, y;
    ll v;
    for(int j = 0; j < m; j++) {
      scanf("%d %d %lld", &x, &y, &v);
      e[j] = edge(min(x, y), max(x, y), v);
      //par[j] = x;
      //graph[x].push_back(y);
      //dist[j] = v;
    }
    
    kruskal(n, m);
    
    // build level
    level[1] = 0;
    par[1] = 1;
    build_level(1, 1, 0);
    
    for(int j = 0; j < a.size(); j++) {
      //printf("%d ", a[j]);
      pos[a[j]].insert(j+1);
    }
    //printf("\n");
    
    // calculate dp
    calc_dp(n);
    
    // build segtree
    build(1, 1, a.size());
    
    for(int j = 0; j < s; j++) {
      scanf("%d %d", &x, &y);
      
      // level of x must be >= than level of y
      if (level[x] < level[y]) {
        int aux = x; x = y; y = aux;
      }
      
      pair<int, int> l = lca(x, y);
      
      printf("lca(%d, %d): %d %d\n", x, y, l.F, l.S);

      int e1 = *pos[x].begin();      
      int b1 = get_lower_bound(e1, l.F);
      
      int e2 = *pos[y].begin();      
      int b2 = get_lower_bound(e2, l.S);
      
      printf("%d %d\n", b1, e1);
      ll q1 = query(1, 1, a.size(), b1+1, e1).value;
     
      printf("%d %d\n", b2, e2);
      ll q2 = query(1, 1, a.size(), b2+1, e2).value;
      printf("%lld\n", min(q1, q2));
    }
    
  }
  
  return 0;
}
