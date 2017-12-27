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
#define pii pair<int, int>
#define qpii queue<pii>
#define mp make_pair

int INF = N * M * N;

int n, m, p;
int dp[N][M];
int a[N][M];

vector<pii> s[N * M];

int d_x[] = {0, 0, 1, -1};
int d_y[] = {1, -1, 0, 0};

void bfs(int node) {

  qpii q;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(a[i][j] != node)
        dp[i][j] = INF;
      else
        q.push({i, j});
  
  while(!q.empty()) {
    int row = q.front().first, col = q.front().second;
    int dist = dp[row][col];
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int new_row = row + d_x[i], new_col = col + d_y[i]; 
      if(new_row < 0 || new_row >= n ||new_col < 0 || new_col >= n || dp[new_row][new_col] <= dist + 1) continue;
      dp[new_row][new_col] = dist + 1;
      q.push({new_row, new_col});
    }
  }
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(a[i][j] != node + 1)
        dp[i][j] = INF;
}

int solve_dp() {

  for(int i = 0; i < s[1].size(); i++) {
    int row = s[1][i].first, col = s[1][i].second;
    dp[row][col] = row + col;
  }

  for(int i = 2; i <= p; i++) {
    if(s[i].size() * s[i-1].size() < 300 * 300 * 10)
      for(int j = 0; j < s[i].size(); j++) {
        for(int k = 0; k < s[i-1].size(); k++) {
          int row = s[i][j].first, col = s[i][j].second;
          int other_row = s[i-1][k].first, other_col = s[i-1][k].second;
            
          int other_dp = dp[other_row][other_col];
          int dist = abs(row-other_row) + abs(col-other_col);
       
          dp[row][col] = min(dp[row][col], other_dp + dist);
        }
      }
    else
      bfs(i-1);
  }
  
  int ans = INF;
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
      scanf("%d", &a[i][j]);
      s[a[i][j]].push_back(make_pair(i, j));
    }
  }

  printf("%d\n", solve_dp());

  return 0;
}
