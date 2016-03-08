#include <bits/stdc++.h> 

#define MAX 200000
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

data t[4*MAX];

data make_data(ll val) {
	data result;
	result.value = val;
	result.orOperation = false;
	return result;
};

data combine(data l, data r) {
	data result;
	result.value = (l.orOperation ? l.value ^ r.value : l.value | r.value);
	result.orOperation = !l.orOperation;	
	return result;
}

void build(int id, ll a[], int b, int e) {

	if(b == e) {t[id] = make_data(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, a, b, m);
	build(2*id + 1, a, m + 1, e);

	t[id] = combine(t[2*id], t[2*id + 1]);
	//printf("t[%d] = %lld, l: %d, r: %d\n", id, t[id].value, 2*id, 2*id + 1);
};

void update(int id, int b, int e, int pos, ll val){

	if(b == e) { t[id] = make_data(val); return; }

	int m = (b+e)/2;

	if(pos <= m)
		update(2*id, b, m, pos, val);
	else
		update(2*id + 1, m+1, e, pos,val);
	
	t[id] = combine(t[2*id], t[2*id + 1]);

}

data query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id, b, m, i, j);
	if(i > m) return query(2*id+1, m+1, e, i, j);
	return combine(query(2*id, b, m, i, m), query(2*id+1, m+1, e, m+1,j));
};


int n, m;
ll x, y;

int main() {
 
    while(scanf("%d %d", &n, &m) != EOF){

		n = pow(2, n);
        ll v[MAX];
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &v[i]);
        }

		build(1, v, 1, n);

        for(int i = 0; i < m; i++) {
            scanf("%lld %lld", &x, &y);
            update(1, 1, n, x, y);
            printf("%lld\n", query(1, 1, n, 1, n).value);
        }
    }

	return 0; 
}
