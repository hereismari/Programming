#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
#define MAX_ROOT 320
#define ll long long

int n, m, root;
int b[MAX], lazy[MAX_ROOT];

int get_value(int index) {
  return max(0, b[index] + lazy[index/root]);
}

void update(int index) {
  
  int v = get_value(index);
  if(v == 0) return;
  
  int begin = max(0, index - v), end = min(n-1, index + v);
  
  for(int i = begin; i <= end;) {
    if(i % root == 0 && i + root - 1 <= end) {
      lazy[i/root]--;
      i += root;
    }
    else {
      b[i] = max(0, b[i] - 1);
      i++;
    }
  }
}

ll get_sum() {

  ll res = 0;
  for(int i = 0; i < n; i++) {
     //printf("**%d %d\n", i, get_value(i));
     res += get_value(i);
  }
  return res; 
}

int main() {

  scanf("%d %d", &n, &m);
  root = (int)sqrt(n) + 1;
  
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);
  
  int x;
  for(int i = 0; i < m; i++) {
    scanf("%d", &x);
    update(x-1);
    //printf("%lld\n", get_sum());
  }
  
  printf("%lld\n", get_sum());

  return 0;
}
