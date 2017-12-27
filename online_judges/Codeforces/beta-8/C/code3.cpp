#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAX 26
#define MAX2 33554432
int init_x, init_y, n;
int x[MAX], y[MAX], order[MAX2];
ll dp[MAX2];

ll dist(ll x1, ll y1, ll x2, ll y2) {
  return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2); 
}

ll solve_dp(int bitmask, int o=0) {

  if(dp[bitmask] != -1)
    return dp[bitmask];
  
  int cont = 0, index = 0;
  for(int i = 0; i < n; i++) {
    if(!(bitmask & (1 << i))) { cont++; index = i; }
  }
  
  if(cont == 0) {
    return 0;
  }
  else if(cont == 1) {
    order[o] = index + 1;
    order[o+1] = 0;
    return dist(init_x, init_y, x[index], y[index]) * 2;
  }
  else {
    ll d = MAX2;
    for(int i = 0; i < n; i++) {
      if(!(bitmask & (1 << i))) {
        for(int j = 0; j < n; j++) {
          if(!(bitmask & (1 << j)) && j != i) {
            ll new_value = dist(init_x, init_y, x[i], y[i]) + dist(x[i], y[i], x[j], y[j]) + dist(init_x, init_y, x[j], y[j]) + 
                           solve_dp((bitmask | (1 << i) | (1 << j)), o + 3);                        
            
            if(new_value < d) {
              d = new_value;
              order[o] = i + 1;
              order[o+1] = j + 1;
              order[o+2] = 0;
            }
          }
        }
      }
    }
      
    dp[bitmask] = d;
    return d;
  }
  
}

int main() {
  
  for(int i = 0; i < MAX2; i++) { dp[i] = -1; order[i] = -1; }

  scanf("%d %d", &init_x, &init_y);
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }

  ll ans = solve_dp(0);
  printf("%lld\n", ans);
  
  printf("0 ");
  int i = 0;
  while(order[i] != -1) {
    printf("%d ", order[i++]);
  }
  printf("\n");
  

  return 0;
}
