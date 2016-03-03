#include <bits/stdc++.h>
#define maxnodes 5010
#define ll long long int

using namespace std;

ll nodes = maxnodes, src, dest;
ll dist[maxnodes], q[maxnodes];
int work[maxnodes];

struct Edge {
  ll to, rev;
  ll f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(ll s, ll t, ll cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, cap};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
	
  fill(dist, dist + nodes, -1);
  
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

ll dinic_dfs(ll u, ll f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

ll maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  ll result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}

int main() {
    
    int n,m,u,v,c;
    scanf("%d %d",&n,&m);
    
    for(int i = 0; i < m; i++){
		
		scanf("%d %d %d",&u,&v,&c);
		addEdge(u,v,c);
		
    }
    
    printf("%lld\n",maxFlow(1,n));
    
    return 0;
}
