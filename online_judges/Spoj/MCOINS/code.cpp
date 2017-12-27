#include <bits/stdc++.h>

using namespace std;

#define MAX 1000050
#define P 1
#define V 2
#define U 0

int dp[MAX], k, l, m;

int main() {

  for(int i = 0; i < MAX; i++) dp[i] = -1;

  scanf("%d %d %d", &k, &l, &m);
  
  dp[0] = P;
  for(int i = 1; i < MAX; i++) {
    
    int v1 = dp[i-1];
    int vk = i-k < 0 ? U: dp[i-k];
    int vl = i-l < 0 ? U: dp[i-l];
    
    if(vk == U && vl == U) {
      if(v1 == V)
        dp[i] = P;
      else
        dp[i] = V;
    } else if(vk == U) {
      if(v1 == V && vl == V)
        dp[i] = P;
      else
        dp[i] = V; 
    } else if(vl == U) {
      if(v1 == V && vk == V)
        dp[i] = P;
      else
        dp[i] = V; 
    } else {
      if(v1 == V && vl == V && vk == V)
        dp[i] = P;
      else
        dp[i] = V; 
    }
    
  }
  
  
  int n;
  for(int i = 0; i < m; i++) {
    scanf("%d", &n);
    printf("%c", dp[n] == V ? 'A' : 'B');
  }
  
  printf("\n");
  
  return 0;
}
