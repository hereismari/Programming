#include <bits/stdc++.h>
 
#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) + 1)
#define MID(left, right) ((left + right) >> 1)
 
#define MAX 100010
#define ll long long int
 
using namespace std;
 

ll lazy[4 * MAX];
ll tree[4 * MAX];
ll arr[MAX];
 
void doLazy(int i, int left, int right) {
  if (lazy[i]) {
    tree[i] += (right - left + 1) * lazy[i];
    if (left != right) {
      lazy[LEFT(i)] += lazy[i];
      lazy[RIGHT(i)] += lazy[i];
    }
    lazy[i] = 0;
  }
}
 
void buildTree(int i, int left, int right){
  if(left == right) tree[i] = arr[left];
  else {
    int mid = MID(left, right);
 
    buildTree(LEFT(i), left, mid);
    buildTree(RIGHT(i), mid + 1, right);
 
    tree[i] = tree[LEFT(i)] + tree[RIGHT(i)];
  }
}
 
void update(int i, int left, int right, int x, int y, ll val) {
  
  doLazy(i, left, right);
   
  if(right < x || left > y) return;
  else if(left >= x && right <= y) {
    lazy[i] += val;
    doLazy(i, left, right);
  }
  else {
    int mid = MID(left, right);
 
    update(LEFT(i), left, mid, x, y, val);
    update(RIGHT(i), mid + 1, right, x, y, val);
 
    tree[i] = tree[LEFT(i)] + tree[RIGHT(i)];
  }
}
 
ll query(int i, int left, int right, int x, int y) {
  
  doLazy(i, left, right);
 
  if(right < x || left > y) return 0;
  else if(left >= x && right <= y) return tree[i];
  else{
    int mid = MID(left, right);
 
    return query(LEFT(i), left, mid, x, y) +
           query(RIGHT(i), mid + 1, right, x, y);
  }
}
 
int t, x, y, x2, y2, c, q, n;
ll value;

int main() {

	scanf("%d",&t);
    while(t--) {
		
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
        scanf("%d %d", &n, &c);
        
        while(c--) {
			scanf("%d", &q);
			if(!q) {
                scanf("%d %d %lld", &x, &y, &value);
                update(1, 1, n, x, y, value);
            }
            else {
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(1, 1, n, x, y));
            }
        }
    }
	return 0;
}
