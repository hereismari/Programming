#include<bits/stdc++.h>

#define MAX 100008
#define MAX_LOG 100
#define ll long long int

using namespace std;

int n,m,child;
int T[MAX],P[MAX][MAX_LOG], L[MAX];
ll d[MAX], w[MAX];

int buildLevel(int i) {
   if(L[i] != -1) return L[i];
   return (L[i] = buildLevel(T[i]) + 1);
}

ll buildDistance(int i) {
    if(d[i] != -1) return d[i];
    return d[i] = buildDistance(T[i]) + w[i];
}

void buildLCA() {

  //we initialize every element in P with -1
      for (int i = 0; i < n; i++)
          for (int j = 0; 1 << j < n; j++)
              P[i][j] = -1;
   
  //the first ancestor of every node i is T[i]
      for (int i = 0; i < n; i++) P[i][0] = T[i];
   
  //bottom up dynamic programing
      for (int j = 1; 1 << j < n; j++)
         for (int i = 0; i < n; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
}

int LCA(int p, int q) {
      
      int tmp, log, i;
      //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
      //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return T[p];
  }

int main() {

	int t, x, y;
    ll v;

	while(scanf("%u",&t) != EOF && t != 0) {
		
        memset(L, 0, sizeof L);
		memset(T, -1,sizeof T);
        memset(d, -1, sizeof d);

        d[0] = 0;
        L[0] = 0;
        w[0] = 0;

        n = t;

		for(int j = 1; j <= n-1; j++){
			scanf("%d %lld", &x, &v);
            T[j] = x;
            w[j] = v;
			L[j] = -1;
		}

		for(int i = 1; i <= n-1; i++) {
            buildLevel(i);
            buildDistance(i);
        }

		buildLCA();

		scanf("%d", &m);
		while(m--){
			scanf("%d %d", &x, &y);
            int lca = LCA(x, y);
			if(m == 0) 
                printf("%lld\n", d[x] + d[y] - 2*d[lca]);
            else
                printf("%lld ", d[x] + d[y] - 2*d[lca]);
		}
	}

	return 0;
}
