#include <bits/stdc++.h>

using namespace std;

const int INF = 100010;

struct node {
  int pos1, pos2, pos3;
};

bool compare_node(const node &n1, const node &n2) {
  return n1.pos1 < n2.pos1;
}

int bit[100010];
void clear_bit() {
  fill(bit, bit + 100010, 100010);
}

int get_min(int index) {
  int res = 100010;
  while(index > 0) {
    res = min(res, bit[index]);
    index -= (index & -index);
  }
  return res;
}

void put_value(int index, int value) {
  while(index < 100010) {
    bit[index] = min(bit[index], value);
    index += (index & -index);
  }
}

int main() {
  
  int t;
  scanf("%d", &t);
  while(t--) {
  
    int n;
    scanf("%d", &n);
    clear_bit();
    
    node a[n];
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &a[i].pos1, &a[i].pos2, &a[i].pos3);
    }
    
    sort(a, a + n, compare_node);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int min_bit = get_min(a[i].pos2);
      if(min_bit > a[i].pos3) ans++;
      put_value(a[i].pos2, a[i].pos3);
    }
  
    printf("%d\n", ans);
  }

  return 0;
}

/*
P1: 1, 2, 3
P2: 2, 3, 4
P3: 3, 4, 1
P4: 4, 1, 2
*/
