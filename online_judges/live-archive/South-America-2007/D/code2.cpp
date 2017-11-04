#include <bits/stdc++.h>

using namespace std;

#define MAX_V 120
#define MAX_STRINGS 100


int v1[20], v2[20];
int n;

int back(int v[], int index) {
  
  if(index <= 2) return 0;
  if(v[index] == 0) return back(v, index-1);
  
  int ans = 0;
  for(int i = 1; i <= index; i++) {
    for(int j = 1; j <= index; j++) {
       if(v[i] > 0 && v[j] > 0 && v[index] > 0 && index < i + j) {
          if(i == j && j == index) break;
          if(i == j && v[i] != 2) break;
          if(i == index && v[i] != 2) break;
          if(j == index && v[j] != 2) break;
          v[i]--;
          v[j]--;
          v[index]--;
          if(v[index] > 0) ans = max(ans, 1 + back(v, index));
          else ans = max(ans, 1 + back(v, index-1));
          v[i]++;
          v[j]++;
          v[index]++;
       }
    }
  }
  
  for(int i = 1; i < index; i++) ans = max(ans, back(v, index-1));
  
  return ans;
}


int main() {
 
  while(scanf("%d", &n) != EOF) {
    
    if(n == 0) break;
    
    memset(v1, 0, sizeof v1);
    memset(v2, 0, sizeof v2);
    
    int x;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      if(i % 2 == 0) v1[x]++;
      else v2[x]++;
    }
  
    int ans1 = 0, ans2 = 0;
    int res1 = 0, res2 = 0;
    
    for(int i = 1; i <= 13; i++) {
      ans1 += v1[i]/3; v1[i] = v1[i] - v1[i]/3 * 3;
      ans2 += v2[i]/3; v2[i] = v2[i] - v2[i]/3 * 3;
    }
/*    
    for(int i = 1; i <= 13; i++) {
      printf("v1[%d] = %d\n", i, v1[i]);
    }
    
    for(int i = 1; i <= 13; i++) {
      printf("v2[%d] = %d\n", i, v2[i]);
    }
  */    
    
    if(ans1 > ans2) printf("1\n");
    else if(ans2 > ans1) printf("2\n");
    else {
      res1 = back(v1, 13);
      res2 = back(v2, 13);
      if(res1 > res2) printf("1\n");
      else if(res2 > res1) printf("2\n");
      else printf("0\n");
    }
    
  }
       
    return 0;
}
