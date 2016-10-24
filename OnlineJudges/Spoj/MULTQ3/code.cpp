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
    int mod3;
};

data seg_tree[4*MAX];
int lazy[MAX];
ll a[MAX];

data make_data(ll value){
	data result;
	result.value = value;
	result.mod3 = (value % 3 == 0);
	return result;
};

data combine(data l, data r) {
	data result;
	result.value = l.value + r.value;
	result.mod3 = l.mod3 + r.mod3;	
	return result;
}

void build(int id, int b, int e){

	if(b == e) { seg_tree[id] = make_data(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, b, m);
	build(2*id + 1, m + 1, e);

	seg_tree[id] = combine(seg_tree[2*id], seg_tree[2*id + 1]);
};

void update(int id, int b, int e, int i, int j, ll value){

    if(lazy[id] != 0) { //needs to be updated
        seg_tree[id].value += lazy[id];
        seg_tree[id].mod3 = seg_tree[id].value % 3;
    
        if(b != e) { // children are lazy
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }
       
        lazy[id] = 0;
    }

	if(b > e || b > j || e < i) return; //segment is not in the interval
    if(b >= i && e <= j) {
        seg_tree[id].value += value;
        seg_tree[id].mod3 = seg_tree[id].value % 3;
        if(b != e) {
            lazy[2*id] += value;
            lazy[2*id+1] += value;
        }
        return;
    }

	int m = (b+e)/2;
	update(2*id, b, m, i, j, value);
	update(2*id + 1, m+1, e, i, j, value);
	
	seg_tree[id] = combine(seg_tree[2*id], seg_tree[2*id + 1]);
}

data query(int id, int b, int e, int i, int j) {
	
	if(b > e || b > j || e < i) return make_data(1); // Out of range

	if(lazy[id] != 0) { // This node needs to be updated
		seg_tree[id].value += lazy[id]; // Update it
        seg_tree[id].mod3 = seg_tree[id].value % 3;

		if(b != e) {
			lazy[id*2] += lazy[id]; // Mark child as lazy
			lazy[id*2+1] += lazy[id]; // Mark child as lazy
		}

		lazy[id] = 0; // Reset it
	}

	if(b >= i && e <= j) // Current segment is totally within range [i, j]
		return seg_tree[id];

	int m = (b+e)/2;
	data q1 = query(id*2, b, m, i, j); // Query left child
	data q2 = query(id*2 + 1, m+1, e, i, j); // Query right child

	data res = combine(q1, q2); // Return final result
	
	return res;
}


int n, m;
int c, x, y;

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1; i <=n; i++) a[i] = 0;
	build(1, 1, n);

	memset(lazy, 0, sizeof lazy);

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &c, &x, &y);
        if(c == 0) {
            update(1, 1, n, x+1, y+1, 1);
        }
        else {
            printf("%d\n", query(1, 1, n, x+1, y+1).mod3);
        }
    }

    return 0;
}
