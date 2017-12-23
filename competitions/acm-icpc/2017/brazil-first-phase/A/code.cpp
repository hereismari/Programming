#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define inf 0x7fffffff

int arr[MAX];
int tree[4 * MAX];
int lazy[4 * MAX];

void build_tree(int node, int a, int b) {
	if(a == b)
	  tree[node] = arr[a]; // leaf node
	else if(a < b) {
	  int m = a + (b-a)/2;
	
    build_tree(node * 2, a, m); // Init left child
    build_tree(node * 2 + 1, m + 1, b); // Init right child

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Init root value
  }
}

void update_tree(int node, int a, int b, int i, int j, int value) {
  // This node needs to be updated
  if(lazy[node] != 0) {
	  tree[node] += lazy[node]; // Update it

    if(a != b) {
	    lazy[node * 2] += lazy[node]; // Mark child as lazy
    	lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
    }

	  lazy[node] = 0; // Reset it
  }
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
	if(a >= i && b <= j) { // Segment is fully within range
    
    tree[node] += value;

	  if(a != b) { // Not leaf node
		  lazy[node * 2] += value;
		  lazy[node * 2 + 1] += value;
	  }
	}
	else {
	  int m = a + (b-a)/2;
	  update_tree(node * 2, a, m, i, j, value); // Updating left child
	  update_tree(node * 2 + 1, m + 1, b, i, j, value); // Updating right child
	  tree[node] = max(tree[node * 2], tree[node * 2+1]); // Updating root with max value
  }
}


int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}

int main() {
  
  int n, q;
  scanf("%d %d", &n, &q);
  
	for(int i = 0; i < n; i++) arr[i] = 1;
	build_tree(1, 0, n-1);
	
	for(int i = 0; i < q; i++) {
	  int b, e;
	  scanf("%d %d", &b &e);
	  update_tree(1, 0, n-1, b, e, query_tree();
	}

	memset(lazy, 0, sizeof lazy);

	update_tree(1, 0, n-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	update_tree(1, 0, n-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	update_tree(1, 0, n-1, 10, n-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

	cout << query_tree(1, 0, n-1, 0, n-1) << endl; // Get max element in range [0, N-1]
}
