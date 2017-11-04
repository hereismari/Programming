#include <bits/stdc++.h>

using namespace std;

int a1[15], a2[15];
int n;

int aux_pow[15];
int dp[1600000];

int get_hash(vector<int> &v){
  int res = 0;
  for(int i = 0; i < 13; ++i) res += v[i] * aux_pow[i];
  return res;
}

int solve(vector<int> &v){
  
  int h = get_hash(v);
  
  if(h == 0) return 0;
  if(dp[h] != -1) return dp[h];
  
  int last_index = -1;
  for(int i = 12; i >= 0; i--)
    if(v[i] > 0) { last_index = i; break; }
   
  int last_value = v[last_index];
  --v[last_index];
      
  if(v[last_index] == 0) {
    for(int i = 0; i < last_index; i++) {
	    if(v[i] > 0) {
		    --v[i];
		    for(int j = 0; j <= i; ++j) {
			    if(v[j] > 0 && i + j >= last_index) {
				    --v[j];
				    dp[h] = max(dp[h], 1 + solve(v));
				    ++v[j];
			    }
		    }
		    ++v[i];
	    }
    }
  }
  else {
   v[last_index] = 0;
   for(int i = 0; i < last_index; i++) {
        if(v[i] > 0){
            --v[i];
            dp[h] = max(dp[h], 1 + solve(v));
            ++v[i];
        }
    }
  }

  dp[h] = max(dp[h], solve(v));
  v[last_index] = last_value;

  return dp[h];
}

int main() {

  aux_pow[0] = 1;
  for(int i = 1; i < 13; i++) aux_pow[i] = aux_pow[i - 1] * 3;
 
  while(scanf("%d", &n) != EOF) {
    
    if(n == 0) break;
    
    memset(a1, 0, sizeof a1);
    memset(a2, 0, sizeof a2);
    
    int x;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      if(i % 2 == 0) a1[x-1]++;
      else a2[x-1]++;
    }
  
    int ans1 = 0, ans2 = 0;
    int res1 = 0, res2 = 0;
    
    for(int i = 0; i < 13; i++) {
      ans1 += a1[i]/3; a1[i] = a1[i] % 3;
      ans2 += a2[i]/3; a2[i] = a2[i] % 3;
    }

    vector<int> v1(a1, a1 + 13);
    vector<int> v2(a2, a2 + 13);
      
    if(ans1 > ans2) printf("1\n");
    else if(ans2 > ans1) printf("2\n");
    else {
      memset(dp, -1, sizeof dp);
      res1 = solve(v1);
      res2 = solve(v2);
      if(res1 > res2) printf("1\n");
      else if(res2 > res1) printf("2\n");
      else printf("0\n");
    }
    
  }
       
    return 0;
}
