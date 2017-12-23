#include <bits/stdc++.h>
#define MAX 12
#define MAX_2 10010
#define pb push_back

using namespace std;

const int INF=10000;

int s[MAX][MAX], r[MAX][MAX], dist[MAX][MAX];

bool visited[MAX_2];
vector<int> adj[MAX_2];
int n, m, t, matched[MAX_2];
queue<pair<int, int> > q;

bool match(int x) {
    visited[x] = true;
    for(int i = 0; i < adj[x].size(); i++){
        int v = adj[x][i];
        if(!visited[v]){
            visited[v] = true;
            if(matched[v] < 0 || match(matched[v]))
            {
                matched[v] = x;
                matched[x] = v;
                return true;
            }
        }
    }
    return false;
}

void matchMaker() {

    double ans = 0;
    for(int i = 0; i < n; i++){
        memset(visited, false,sizeof visited);
        if(match(i)) ans++;
    }
    printf("P = %.2f\n", ans/n * 100);
}


int main() {

    while(scanf("%d %d", &n, &t) != EOF && (n && m)) {

      for(int i = 0; i < n; i++) scanf("%s", s[i]);
      for(int i = 0; i < n; i++) scanf("%s", r[i]);
          
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
              dist[i][j] = INF;
              if(s[i][j] == 'Z') q.push(mp(i,j));
          }
      }
      
      bfs();

        // dp to define edges
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < m; j++) {
              int dp[size_c[i] + 1][size_b[j] + 1];
              memset(dp, 0, sizeof dp);
              
              for(int k = 1; k <= size_c[i]; k++) {
                for(int l = 1; l <= size_b[j]; l++) {
                  if(c[i][k-1] == b[j][l-1]) dp[k][l] = dp[k-1][l-1] + 1;
                  else dp[k][l] = max(dp[k-1][l], dp[k][l-1]);
                  //printf("%d ", dp[k][l]);        
                }
                //printf("\n");
              }                                        
            
              int aux = dp[size_c[i]][size_b[j]];
              int res = size_c[i] + size_b[j] - 2 * aux;
              
              if(res % 5 == 0) {
                //printf("%d %d\n", i, n + j);
                adj[i].pb(n + j);              
              }
          }

        }

        // get solution
        memset(matched, -1, sizeof matched);
        matchMaker();
    }
    return 0;
}
