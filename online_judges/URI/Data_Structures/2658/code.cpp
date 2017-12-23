#include<bits/stdc++.h>

using namespace std;

#define MAX 100010
#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) | 1)
#define MID(left, right) ((left + right) >> 1)

int tree[MAX * 4][10];
int lazy[MAX * 4], answer[10], aux[10];

void build(int node, int b, int e) {
  if (b == e) { tree[node][1] = 1; return; }
  int mid = MID(b, e);
  build(LEFT(node), b, mid);
  build(RIGHT(node), mid + 1, e);
  tree[node][1] = tree[LEFT(node)][1] + tree[RIGHT(node)][1];
  return;
}

void do_lazy(int node, int b, int e) {
  if (lazy[node]) {
    int v = lazy[node];
    lazy[node] = 0;
    for (int i = 0; i < 9; i++) aux[(i + v) % 9] = tree[node][i];
    for (int i = 0; i < 9; i++) tree[node][i] = aux[i];
    if (b != e) {
      lazy[LEFT(node)] += v;
      lazy[RIGHT(node)] += v;
    }
  }
}

void query(int node, int b, int e, int l, int r) {
  do_lazy(node, b, e);
  if (b > r || e < l) return;
  else if (b >= l && e <= r) {
    for (int i = 0; i < 9; i++) { answer[i] += tree[node][i]; }
  }
  else {
    int mid = MID(b, e);
    query(LEFT(node), b, mid, l, r);
    query(RIGHT(node), mid + 1, e, l, r);
  }
}

void update(int node, int b, int e, int l, int r, int v) {
  do_lazy(node, b, e);
  if (b > r || e < l) return;
  if (b >= l && e <= r) {
    lazy[node] += v;
    do_lazy(node, b, e);
  }
  else {
    int mid = MID(b, e);
    update(LEFT(node), b, mid, l, r, v);
    update(RIGHT(node), mid + 1, e, l, r, v);
    for (int i = 0; i < 9; i++) {
      tree[node][i] = tree[LEFT(node)][i] + tree[RIGHT(node)][i];
    }
  }
}

int get_max() {
  int index_max = -1;
  for (int j = 0; j < 9; j++) {
    if (index_max == -1 || answer[j] >= answer[index_max]) {
      index_max = j;
    }
  }
  return index_max;
}

int t, x, y, c, q, n;

int main() {

	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
  
  scanf("%d %d", &n, &c);
  build(1, 0, n-1);
  
  while(c--) {
    scanf("%d %d", &x, &y);
    memset(answer, 0, sizeof answer);
    query(1, 0, n - 1, x, y);
    int value = get_max();
    update(1, 0, n - 1, x, y, value);
  }
  
  for(int i = 0; i < n; i++) {
    memset(answer, 0, sizeof answer);
    query(1, 0, n - 1, i, i);
    for(int j = 0; j < 9; j++) {
      if(answer[j])
        printf("%d\n", j);
    }
  }

  return 0;
}

