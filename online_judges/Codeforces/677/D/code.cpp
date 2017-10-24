#include <bits/stdc++.h>

using namespace std;


/*

  dp[row][col] = min steps to get here.
  dp[row][col] = row + col where grid[row][col] = 1
  
  dp[row][col] = min(dp[row][col] + 1), where grid[row][col] = grid[row][col]-1
  
  300 * 300 * (300 * 300)

*/

#define N 310
#define M 310

#define ll long long int

ll INF = N * M * N;

int n, m, p;
ll dp[N][M];

vector<pair<int, int> > s[N * M];

ll solve_dp() {

  for(int i = 0; i < s[1].size(); i++) {
    int row = s[1][i].first, col = s[1][i].second;
    dp[row][col] = row + col;
  }

  for(int i = 2; i <= p; i++) {
    for(int j = 0; j < s[i].size(); j++) {
      for(int k = 0; k < s[i-1].size(); k++) {
        
        int row = s[i][j].first, col = s[i][j].second;
        int other_row = s[i-1][k].first, other_col = s[i-1][k].second;
        
        ll other_dp = dp[other_row][other_col];
        ll dist = abs(row-other_row) + abs(col-other_col);
     
        dp[row][col] = min(dp[row][col], other_dp + dist);
      }
    }
  }
  
  ll ans = INF;
  for(int i = 0; i < s[p].size(); i++) {
    ans = min(ans, dp[s[p][i].first][s[p][i].second]);
  }

  return ans;
}

int main() {

  scanf("%d %d %d", &n, &m, &p);
  memset(dp, INF, sizeof dp);
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      s[x].push_back(make_pair(i, j));
    }
  }

  printf("%lld\n", solve_dp());

  return 0;
}
