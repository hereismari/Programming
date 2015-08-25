#include<bits/stdc++.h>
#define MAX 10000
#define MAX_LOG 10000

using namespace std;

int n,m,child;
int T[MAX],P[MAX][MAX_LOG],L[MAX];

int buildLevel(int i) {
   if(L[i] != -1) return L[i];
   return (L[i] = buildLevel(T[i]) + 1);
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

	int t,x,y;
	scanf("%u",&t);
	for(int i = 1; i <= t; i++){
		printf("Case %u:\n",i);
		memset(L,0,sizeof L);
		memset(T,-1,sizeof T);

		scanf("%d",&n);
		for(int j = 1; j <= n; j++){
			scanf("%d",&m);
			while(m--){
				scanf("%d",&x);
				T[x-1] = j-1;
				L[x-1] = -1;
			}
		}

		for(int i = 0 ; i < n; i++) buildLevel(i);
		buildLCA();

		scanf("%d",&m);
		while(m--){
			scanf("%d %d",&x,&y);
			printf("%d\n",LCA(x-1,y-1) + 1);
		}
	}

	return 0;
}
