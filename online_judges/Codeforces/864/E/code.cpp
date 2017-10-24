#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[100][2000];
bool used[100][2000];
int t[100], d[100], p[100];

int n;

int run_dp(int index, int tim) {
  
  if(index >= n) return 0;
  else if(dp[index][tim] != -1) return dp[index][tim];
  
  int ans = 0;
  int usi = 0, not_usi = 0;
  if(tim + t[index] < d[index]) {
    usi = run_dp(index + 1, tim + t[index]) + p[index];
  }
 
  not_usi = run_dp(index + 1, tim);
  
  if(usi > not_usi) {
    used[index][tim] = true;
  }
  
  dp[index][tim] = max(usi, not_usi);
  return dp[index][tim];

}

int main() {

  scanf("%d", &n);
  
  memset(dp, -1, sizeof dp);
  memset(used, false, sizeof used);
  
  for(int i = 0; i < n; i++) {
    scanf(" %d %d %d", &t[i], &d[i], &p[i]);
  }
  
  int ans = run_dp(0, 0);
  vector<int> res;
  
  int i = 0, j = 0;
  while(i < 100 && j < 

  printf("%d\n", ans);

  return 0;
}
