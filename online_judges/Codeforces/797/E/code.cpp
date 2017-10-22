#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
#define mp make_pair
#define MAX_SQRT 320
int n, q, root;
int a[MAX];

struct res {

  int count, next_v;
  res(int c, int v) {
    count = c; next_v = v;
  }

};

int dp[MAX][MAX_SQRT];
int final_v;

int solve_dp(int v, int k) {
  
  if(v >= n) {
    return 0;
  }

  if(dp[v][k] != -1) {
    return dp[v][k];
  }
  
  int r = 1 + solve_dp(v + a[v] + k, k);
  
  dp[v][k] = r;
  return r;
}

int get_answer(int p, int k) {
  
  int r = 0;
  
  if(k < root) {
    r = solve_dp(p, k);
  }
  else {
    while(p < n) {
      p = p + a[p] + k;
      r++;
    }
  }
  
  return r;
}

int main() {

  memset(dp, -1, sizeof dp);
  
  scanf("%d", &n);
  root = (int) sqrt(n) + 1;
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int p, k;
    scanf("%d %d", &p, &k);
    printf("%d\n", get_answer(p-1, k));
  }

  return 0;
}
