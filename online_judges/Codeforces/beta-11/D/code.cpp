#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAX 20
int n, m, adj[MAX][MAX];
ll dp[1 << MAX][MAX];


ll solve_dp(int bitmask, int start, int curr, int l=1) {

  if(dp[bitmask][curr] != -1) return dp[bitmask][curr];
  else {
  
    ll res = adj[curr][start] && l > 2;
    for(int i = start; i < n; i++) {
      if(adj[curr][i] && !(bitmask & (1 << i))) {
        res += solve_dp(bitmask | (1 << i), start, i, l+1);
      }
    }

    dp[bitmask][curr] = res;    
    return dp[bitmask][curr];
  }
}

int main() {

  scanf("%d %d", &n, &m);
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      adj[i][j] = 0;
      
  for(int i = 0; i < 1 << MAX; i++)
    for(int j = 0; j < MAX; j++)
      dp[i][j] = -1;
  
  int node1, node2;
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &node1, &node2);
    node1--; node2--;
    adj[node1][node2] = adj[node2][node1] = 1;
  }

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += solve_dp(1 << i, i, i);
  }

  printf("%lld\n", ans / 2);
  return 0;
}
