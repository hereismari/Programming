#include <bits/stdc++.h>
#define MAX 5000
#define INF 1e9
#define pb push_back
#define ll long long int

using namespace std;

struct Edge {
    int to, rev;
    ll f, cap;
    Edge(int t=0, int r=0, ll fl=0, ll c=0) {
        to = t; rev = r; f = fl; cap = c;
    }
};

vector<Edge> adj[MAX];
int s, t;
ll dist[MAX], q[MAX], work[MAX];

void clear() { for(int i = 0; i < MAX; i++) adj[i].clear(); }

void makeEdge(int a, int b, ll c) {

    Edge e1 = Edge(b, adj[b].size(), 0, c);
    Edge e2 = Edge(a, adj[a].size(), 0, c);

    adj[a].pb(e1);
    adj[b].pb(e2);
}

ll dfs(int node, ll f) {

    if(node == t) return f;
    for(ll &i = work[node]; i < adj[node].size(); i++){
        Edge &e = adj[node][i];
        if (e.cap <= e.f) continue;
        if(dist[e.to] == dist[node] + 1) {
            ll df = dfs(e.to, min(f, e.cap - e.f));
            if(df > 0) {
                e.f += df;
                adj[e.to][e.rev].f -= df;
                return df;
           }
        }
    }

    return 0;
}

bool bfs() {
    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    int tail = 0;
    q[tail++] = s;
    for(int head = 0; head < tail; head++) {
        int u = q[head];
        for(int i = 0; i < adj[u].size(); i++){
            Edge &e = adj[u][i];
            if(dist[e.to] < 0 && e.f < e.cap) {q[tail++] = e.to; dist[e.to] = dist[u] + 1; }
        }
    }
    return dist[t] >= 0;
}

ll dinic() {
    ll ans = 0;
    while(bfs()){
       memset(work, 0, sizeof work);
       while(ll aux = dfs(s, INT_MAX)) ans += aux; 
    }
    return ans;
}

int main() {

    int n, e, a, b;
    ll c;
    while(scanf("%d %d", &n, &e) != EOF && (n || e)) {
        clear();
        for(int i = 0; i < e; i++){
            scanf("%d %d %lld", &a, &b, &c);
            makeEdge(a-1, b-1, c);
        }
    
        s = 0;
        t = n-1;
        printf("%lld\n", dinic());

    }
    return 0;
}
