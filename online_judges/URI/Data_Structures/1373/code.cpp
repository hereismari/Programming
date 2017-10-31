#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int k;
char s1[MAX], s2[MAX];
int match[MAX][MAX], dp[MAX][MAX];

int main() {

  while(scanf("%d", &k) != EOF) {
  
    if(k == 0) break;
    scanf("\n%s\n%s", s1, s2);
  
    int n = strlen(s1);
    int m = strlen(s2);
    
    memset(dp, 0, sizeof dp);
    memset(match, 0, sizeof match);
    
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(s1[i-1] == s2[j-1]) match[i][j] = 1 + match[i-1][j-1];
        else match[i][j] = 0; 
      }
    }
    
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
      
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
        if(match[i][j] >= k) dp[i][j] = max(dp[i][j], dp[i-k][j-k] + k);
        if(match[i][j] > k) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1); 
      }
    }
    
    printf("%d\n",dp[n][m]);
  
  }

  return 0;
}
