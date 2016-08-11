/* Solution to http://codeforces.com/problemset/problem/339/D */

#include <bits/stdc++.h> 

#define MAX 500000
#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct data {
	ll value;
	bool orOperation;
};

data seg_tree[4*MAX];
int lazy[MAX];

data make_data(ll value){
	data result;
	result.value = value;
	result.orOperation = false;
	return result;
};

data combine(data l, data r) {
	data result;
	result.value = (l.orOperation ? l.value ^ r.value : l.value | r.value);
	result.orOperation = !l.orOperation;	
	return result;
}

void build(int id, ll a[], int b, int e){

	if(b == e) { seg_tree[id] = make_data(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, a, b, m);
	build(2*id + 1, a, m + 1, e);

	seg_tree[id] = combine(seg_tree[2*id], seg_tree[2*id + 1]);
};

void update(int id, int b, int e, int i, int j, ll value){
    
    if(lazy[id] != 0) { //needs to be updated
        seg_tree[id].value += lazy[id];
    
        if(b != e) { // children are lazy
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }
       
        lazy[id] = 0;
    }

	if(b > e || b > j || b < i) return; //segment is not in the interval
    if(b >= i && e <= j) {
        seg_tree[id].value += value;
        if(b != e) {
            lazy[2*id] += value;
            lazy[2*id+1] += value;
        }
    }

	int m = (b+e)/2;
	update(2*id, b, m, i, j, value);
	update(2*id + 1, m+1, e, i, j, value);
	
	seg_tree[id] = combine(seg_tree[2*id], seg_tree[2*id + 1]);
}



data query(int id, int b, int e, int i, int j) {
	
	if(b > e || b > j || e < i) return -inf; // Out of range

	if(lazy[id] != 0) { // This node needs to be updated
		tree[id] += lazy[id]; // Update it

		if(b != e) {
			lazy[id*2] += lazy[id]; // Mark child as lazy
			lazy[id*2+1] += lazy[id]; // Mark child as lazy
		}

		lazy[id] = 0; // Reset it
	}

	if(b >= i && e <= j) // Current segment is totally within range [i, j]
		return seg_tree[node];

	int m = (b+e)/2;
	data q1 = query(id*2, b, m, i, j); // Query left child
	data q2 = query(id*2 + 1, m+1, e, i, j); // Query right child

	data res = combine(q1, q2); // Return final result
	
	return res;
}


int n, m;
ll x, y;

int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;

	build_tree(1, 0, N-1);

	memset(lazy, 0, sizeof lazy);

	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}
