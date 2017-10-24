#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;
  scanf("%d", &n);
  
  int a[n], b[n];
  map<int, int> m;
  for(int i = 0; i < n; i++) { scanf("%d", &a[i]); m[a[i]] = 1; }
  for(int i = 0; i < n; i++) { scanf("%d", &b[i]); m[b[i]] = 1; }

  int count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(m.find((a[i] ^ b[j])) != m.end()) count++;
    }
  }
  
  if(count % 2) {
    printf("Koyomi\n");
  }
  else {
    printf("Karen\n");
  }

  return 0;
}
