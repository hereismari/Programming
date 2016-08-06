#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define MAXN 100
#define ll long long int

ll cap[MAXN][MAXN];
int n, s, t;
int p[MAXN];
ll dist[MAXN];
 
ll augpath(int v, ll mf) {
  
  if(v == s) return mf;
  else if (p[v] != -1) {
  	mf = augpath(p[v], min(mf, cap[p[v]][v]));
  	cap[p[v]][v] -= mf;
  	cap[v][p[v]] += mf;
  	return mf;
  }
  
  else return 0;
}

void bfs() {
	
	memset(p, -1, sizeof p);
	for(int i = 0; i < MAXN; i++) dist[i] = INF;
	
	dist[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for(int v = 0; v < MAXN; v++) {
			if(cap[u][v] > 0 && dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
				p[v] = u;
			}
		}
	}
}

 
ll maxflow(int so, int si){
  
  s = so; t = si;
  
  ll flow = 0;
  while(true) {
  
    // BFS
    bfs();
    
    // augment path and stop condition
    ll f = augpath(t, INF);
    if(!f) break;
    flow += f;
  }
	
  return flow;
}

void add(int u, int v, int c) {
	cap[u][v] += c;
	cap[v][u] += c;
}

void clean_graph() {
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++) {
			cap[i][j] = 0;
		}
}


int conv(char c) {
	if (isupper(c)) return c - 'A';
	return c - 'a' + 27;
}

int main() {
	
	int e, u, v, c;
	char a, b;
	
	scanf("%d", &e);
	
	clean_graph();
	
	for(int i = 0; i < e; i++) {
		scanf("\n%c %c %d", &a, &b, &c);
		u = conv(a); v = conv(b);
		if(u != v) add(u, v, c);
	}
	
	printf("%lld\n", maxflow(0, 25));
	return 0;
}
