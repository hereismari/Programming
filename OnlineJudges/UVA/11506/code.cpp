#include <bits/stdc++.h>
 
#define INF 1e9
#define MAXN 800
#define min(a,b) a < b ? a : b
int res[MAXN][MAXN], n;
bool vis[MAXN];
 
int augpath(int so, int si, int mf){
  
  vis[so] = true;
  if(so == si) return mf;
  
  for(int i = 0; i < n; i++)
    if (!vis[i] && res[so][i]) {
       int flow = augpath(i, si, min(mf, res[so][i]));
       if(flow) {
          res[so][i] -= flow;
          res[i][so] += flow;
          return flow;
       }
    }
    return 0;
}
 
int maxflow(int so, int si){
  int ret = 0;
  while (true){
    memset(vis, 0, sizeof vis);
    int flow = augpath(so, si, INF);
    if(!flow) return ret;
    ret += flow;
  }
}
 
int main(){
    
    int n,e,a,b,c;
    while(scanf("%d %d", &n, &e) != EOF && (n || e)) {
	    memset(res, 0, sizeof res);
	    res[0][n] = res[n-1][2*n-1] = INF;
	    for(int i = 0; i < n-2; i++){
	      scanf("%d %d",&a, &c); a--;
	      res[a][n+a] = c;
	    }
	    for(int i = 0; i < e; i++){
	      scanf("%d %d %d",&a, &b, &c); a--; b--;
	      res[n+a][b] = res[n+b][a] = c;
	    }
	    printf("%d\n",maxflow(0, 2*n-1));
	  }

    return 0;
}
