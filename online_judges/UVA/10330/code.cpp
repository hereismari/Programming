#include <bits/stdc++.h>

using namespace std;

const int INFI = 1 << 30;
const int MAXN = 110;
const int START_NODE = 0;
const int END_NODE = 9999;

typedef struct edge {
    int to, flow, cap, next;
} Edge;

Edge E[10100];
int adj[10100];
int allow_map[10100];
int eidx;

void add_edge(int from, int to, int flow) {
    E[eidx].to = to;
    E[eidx].cap = flow;
    E[eidx].flow = 0;
    E[eidx].next = adj[from];
    adj[from] = eidx++;
    E[eidx].to = from;
    E[eidx].cap = 0;
    E[eidx].flow = 0;
    E[eidx].next = adj[to];
    adj[to] = eidx++; 
}
bool bfs(int s, int t) {
    memset(allow_map, -1, sizeof(allow_map));
    queue<int> Q;
    Q.push(s);
    allow_map[s] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int i = adj[cur]; i != -1; i = E[i].next) {
            Edge &e = E[i];
            if(allow_map[e.to] < 0 && e.cap > e.flow) {
                allow_map[e.to] = allow_map[cur] + 1;
                Q.push(e.to);
                if(e.to == t) {
                    return true;
                }
            }
        }
    }
    return false;
}
int dfs(int cur, int end_pt, int minflow) {
    if(cur == end_pt || minflow == 0) return minflow;
    int flow = 0, minf;
    for(int i = adj[cur]; i != -1; i = E[i].next) {
        Edge &e = E[i];
        if(allow_map[cur] + 1 == allow_map[e.to] && (minf = dfs(e.to, end_pt, min(minflow, e.cap - e.flow))) > 0) {
            flow += minf;
            e.flow += minf;
            E[i ^ 1].flow -= minf;
            minflow -= minf;
            if(minflow == 0) break;
        }
    }
    return flow;
}
int dinic(int s, int t) {
    int max_flow = 0;
    while(bfs(s, t)) {
        max_flow += dfs(s, t, INFI);
    }
    
    return max_flow;
}
void read_input(int n) {
    memset(adj, -1, sizeof(adj));
    eidx = 0;
    int nline, b, d, t;
    int from, to, flow;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        add_edge(i, i+MAXN, t);
    }
    scanf("%d", &nline);
    for(int i = 0; i < nline; ++i) {
        scanf("%d%d%d", &from, &to, &flow);
        add_edge(from+MAXN, to, flow);
    }
    scanf("%d%d", &b, &d);
    for(int i = 0; i < b; ++i) {
        scanf("%d", &t);
        add_edge(START_NODE, t, INFI);
    }
    for(int i = 0; i < d; ++i) {
        scanf("%d", &t);
        add_edge(t+MAXN, END_NODE, INFI);
    }
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        read_input(n);
        int maxflow = dinic(START_NODE, END_NODE);
        printf("%d\n", maxflow);
    }
    return 0;
}
