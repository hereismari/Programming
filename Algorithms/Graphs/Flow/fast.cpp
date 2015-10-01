#include <bits/stdc++.h>

#define MAX_E 40000
#define MAX_V 5400 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

using namespace std;
int src, dest;
ll dist[MAX_V], q[MAX_V], work[MAX_V];

struct Edge {
  int to, rev;
  ll f, cap;
};

vector<Edge> g[MAX_V];

void clear() {
   for(int i = 0; i < MAX_V; i++) g[i].clear();
}

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, cap};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  memset(dist, -1, sizeof dist);
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < g[u].size(); j++) {
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

ll dinic_dfs(int u, ll f) {
  if (u == dest) return f;
  for (ll &i = work[u]; i < g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      ll df = dinic_dfs(v, min(f, e.cap - e.f));
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
    memset(work, 0, sizeof work);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}

 
int main(){
    
    int n,e,a,b,c;
    while(scanf("%d %d", &n, &e) != EOF && (n || e)) {
	clear();
        for(int i = 0; i < e; i++){
          scanf("%d %d %d",&a, &b, &c); a--; b--;
          addEdge(a, b, c);	      
        }
	    printf("%lld\n",maxFlow(0, n-1));
    }

    return 0;

}
