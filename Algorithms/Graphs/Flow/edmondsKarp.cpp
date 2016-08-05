#include <bits/stdc++.h>
/*
To be verified!
*/
 
 
#define INF 1e9
#define MAXN 100
#define min(a,b) a < b ? a : b

int res[MAXN][MAXN], n, s, t;
int p[MAXN], dist[MAXN];
 
int augpath(int v, int mf) {
  
  if(v == s) return mf;
  else if (p[v] != -1) {
  	mf = augpath(p[v], min(mf, res[p[v]][v]));
  	res[p[v]][v] -= mf;
  	res[v][p[v]] += mf;
  	return mf;
  }
  
  else return 0;
}

void bfs() {
	
	memset(p, -1, sizeof p);
	memset(dist, INF, sizeof dist);
	dist[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for(int v = 0; v < MAXN; v++)
			if(res[u][v] > 0 && dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
				p[v] = u;
			}
	}
}

 
int maxflow(int so, int si){
  
  s = so; t = si;
  
  int flow = 0;
  while(true) {
  
    // BFS
    bfs();
    
    // augment path and stop condition
    int f = augpath(t, INF);
    if(!f) return flow;
    flow += f;
  }
}
 
int main() {
    
    int n, e, a, b, c;
    while(scanf("%d %d", &n, &e) != EOF && (n || e)) {
	    memset(res, 0, sizeof res);
	    res[0][n] = res[n-1][2*n-1] = INF;
	    for(int i = 0; i < n-2; i++){
	      scanf("%d %d", &a, &c); a--;
	      res[a][n+a] = c;
	    }
	    
	    for(int i = 0; i < e; i++) {
	      scanf("%d %d %d", &a, &b, &c); a--; b--;
	      res[n+a][b] = res[n+b][a] = c;
	    }
	    
	    printf("%d\n", maxflow(0, 2*n - 1));
    }
}
