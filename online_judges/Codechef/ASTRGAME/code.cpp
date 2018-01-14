#include <bits/stdc++.h>

using namespace std;

#define MAX 40

int n, dp[MAX][MAX];
set<string> subs;

int solve(int i, int j, string s) {
  if(i > j) return 0;
  else if(dp[i][j] != -1) return dp[i][j];
  else {
  
    bool vis[MAX];
    memset(vis, false, sizeof vis);
    
    for(int k = i; k <= j; k++) {
      string aux = "";
      aux += s[k];
      if(subs.find(aux) != subs.end()) {
        int res = solve(i, k-1, s) ^ solve(k+1, j, s);
        vis[res] = true;
      }
      
      for(int l = k+1; l <= j; l++) {
        aux += s[l];
        if(subs.find(aux) != subs.end()) {
          int res = solve(i, k-1, s) ^ solve(l+1, j, s);
          vis[res] = true;
        }
      }
    }
    
    int mex;
    for(int i = 0;; i++) {
      if(!vis[i]) { mex = i; break; }
    }

    //printf("dp[%d][%d] = %d\n", i, j, mex);
    dp[i][j] = mex;
    return dp[i][j];  
  }

}

int main() {

  int t;
  scanf("%d", &t);

  string s;
  while(t--) {
    cin >> s;
    scanf("%d", &n);
    
    memset(dp, -1, sizeof dp);
    subs.clear();
    
    string aux;
    for(int i = 0; i < n; i++) {
      cin >> aux;
      subs.insert(aux);
    }
  
    printf("%s\n", solve(0, s.size()-1, s) == 0 ? "Tracy" : "Teddy");
  }


  return 0;
}
