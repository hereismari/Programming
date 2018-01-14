#include <bits/stdc++.h>

using namespace std;

#define X 1
#define O 2
#define MAX 200

int dp[3][3][MAX];

int mex(int b, int e, int l) {

  if(dp[b][e][l] != -1) return dp[b][e][l];
  if(l <= 0) return 0;
  
  bool vis[MAX];
  memset(vis, false, sizeof vis);
  
  for(int i = 1; i <= l; i++) {
    for(int j = X; j <= O; j++) {
      if(i == 1 && j == b) continue;
      if(i == l && j == e) continue;
      int res = mex(b, j, i-1) ^ mex(j, e, l-i);
      vis[res] = true;
    }
  }
  
  for(int i = 0;;i++) if(!vis[i]) { dp[b][e][l] = i; break; }
 
  return dp[b][e][l];
}


int main() {

  int n;
  scanf("%d", &n);
  
  while(n--) {
    memset(dp, -1, sizeof dp);
    
    string game_status;
    cin >> game_status;
    
    int b = 0, e = 0, l = 0, cnt = 0;  // we need count to know if Alice began or not
    int ans = 0;
    for(int i = 0; i < game_status.size(); i++) {
      if(game_status[i] == '.') l++;
      else {
        e = ((game_status[i] == 'X') ? X : O);
        ans ^= mex(b, e, l);
        b = e; l = 0; cnt++;
      }
    }

    ans ^= mex (b, 0, l);
    if(cnt & 1) ans = (ans == 0) ? 1 : 0;
    printf("%s\n", ans == 0 ? "Impossible." : "Possible.");
  }
  
  return 0;
}
