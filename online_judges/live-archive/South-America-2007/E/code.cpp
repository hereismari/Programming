#include <bits/stdc++.h>

using namespace std;

#define MAX_V 120
#define MAX_STRINGS 100

#define S second
#define F first
#define INF 1000

char emoticons[MAX_V][MAX_STRINGS];
char s[MAX_V][MAX_STRINGS];

int dp[MAX_V][MAX_V];
int max_match_from[MAX_V];

int n, m;

int solve(int b, int e) {
  if(b > e) return 0;
  if(dp[b][e] != -1) return dp[b][e];

  dp[b][e] = INF;
  if(b + max_match_from[b] <= e) {
    for(int i = b; i <= b + max_match_from[b]; i++) 
      dp[b][e] = min(dp[b][e], 1 + solve(b, i-1) + solve(i+1, e));
    return dp[b][e];
  }
  else return dp[b][e] = solve(b+1, e);
}


int main() {
 
  while(scanf("%d %d", &n, &m) != EOF) {
  
    if(n == 0 && m == 0) break;
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) { 
      scanf("\n%s", emoticons[i]);
    }
    
    for(int i = 0; i < m; i++) {
      // get a line
      scanf("\n%[^\n]s", s[i]);
      
      // get max match for all i (i >= 0 and i < m)
      // where a match is s[i] = emoticon[j] and s[i+1] = emoticon[j+1] ... until the end of emoticon is reached 
      int size_s = strlen(s[i]);
      for(int j = 0; j < size_s; j++) {
        max_match_from[j] = INF;
        // check if is a match starting from j for all emoticons
        for(int k = 0; k < n; k++) {
          if(j + strlen(emoticons[k]) <= size_s) {
              int count = 0;
              while(count < strlen(emoticons[k]) && s[i][j+count] == emoticons[k][count]) count++;
              if(count == strlen(emoticons[k])) {
                max_match_from[j] = min(max_match_from[j], count-1);
              }
          }
        }
        
        //printf("max match %d = %d\n", j, max_match_from[j]);
      }
      
      memset(dp, -1, sizeof dp);
      ans += solve(0, size_s-1);
    }
    printf("%d\n", ans);
  }
     
  return 0;
}
