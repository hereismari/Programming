#include <bits/stdc++.h>
 
#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) + 1)
#define MID(left, right) ((left + right) >> 1)
 
#define MAX 100100
#define ll long long int
 
using namespace std;
 
ll lazy[8 * MAX];
ll tree[8 * MAX];
ll arr[MAX];
 
void doLazy(int i, int left, int right) {
  if(i < 4 * MAX && lazy[i]) {
    int mid = MID(left, right);
    lazy[LEFT(i)] = lazy[i];
    lazy[RIGHT(i)] = lazy[i];

    if((mid - left + 1) % 2 == 0)
        tree[LEFT(i)] = 0;
    else
        tree[LEFT(i)] = lazy[i];

    if((right - mid) % 2 == 0)
        tree[RIGHT(i)] = 0;
    else
        tree[RIGHT(i)] = lazy[i];

    lazy[i] = 0;
  }
}
 
void buildTree(int i, int left, int right){
  lazy[i] = 0;
  if(left == right) tree[i] = arr[left];
  else {
    int mid = MID(left, right);
 
    buildTree(LEFT(i), left, mid);
    buildTree(RIGHT(i), mid + 1, right);
 
    tree[i] = tree[LEFT(i)] ^ tree[RIGHT(i)];
  }
}
 
void update(int i, int left, int right, int x, int y, ll val) {
  
  doLazy(i, left, right);
  
  if(right < x || left > y) return;
  else if(left >= x && right <= y) {
    int aux = (right - left + 1);
    if(aux % 2 == 0) tree[i] = 0;
    else tree[i] = val;
    lazy[i] = val;
  }
  else {
    int mid = MID(left, right);
 
    update(LEFT(i), left, mid, x, y, val);
    update(RIGHT(i), mid + 1, right, x, y, val);
 
    tree[i] = tree[LEFT(i)] ^ tree[RIGHT(i)];
  }
}
 
ll query(int i, int left, int right, int x, int y) {
  
  doLazy(i, left, right);
 
  if(right < x || left > y) return 0;
  else if(left >= x && right <= y) return tree[i];
  else{
    int mid = MID(left, right);
 
    return query(LEFT(i), left, mid, x, y) ^
           query(RIGHT(i), mid + 1, right, x, y);
  }
}

int main() {

  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);

  buildTree(1, 1, n);

  int b, e, x;
  
  //printf("%lld\n", query(1, 1, n, 1, n));
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &b, &e, &x);
    //printf("%d: %d %d %d\n", i, b, e, x);
    update(1, 1, n, b, e, x);
    //printf("%lld\n", query(1, 1, n, 1, n));
    printf("%s\n", query(1, 1, n, 1, n) ? "Possivel" : "Impossivel");   
  }
	return 0;
}
