#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#define MAXN 1000000
#define INF 1000001000

int n, a[MAXN];
int b, c, d , i, m, x;

struct data {
	int ans;
};

data t[2000000];

data combine (data l, data r) {
	data res;
	res.ans = min(l.ans,r.ans);
	return res;
}

data make_data (int val) {
	data res;
	res.ans = val;
	return res;
}

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_data(a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

data query (int v, int tl, int tr, int l, int r) {
	if (l == tl && tr == r)
		return t[v];
	int tm = (tl + tr) / 2;
	if (r <= tm)
		return query (v*2, tl, tm, l, r);
	if (l > tm)
		return query (v*2+1, tm+1, tr, l, r);
	return combine (
		query (v*2, tl, tm, l, tm),
		query (v*2+1, tm+1, tr, tm+1, r)
	);
}

void update(int v, int tl, int tr, int pos, int val){

	if(tl == tr) t[v] = make_data(val);
	else {
		
		int tm = (tl + tr)/2;	
		
		if(tm >= pos)
			update(2*v, tl, tm, pos, val);
		else
			update(2*v + 1, tm + 1, tr, pos, val);
	
		t[v] = combine(t[2*v],t[2*v + 1]);
	}

}

int main(void) {
    int t;
	scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) {
		scanf("%d %d", &x, &m);
		
		for(int j = 0; j < x ; j++)
			scanf("%d", &a[j+1]);
		build(a, 1, 1, x+1);
		printf("Scenario #%d:\n\n",i+1);
		for(int j = 0; j <  m; j++) {
        	scanf("%d %d",&b, &c);
			printf("%d\n\n", query(1, 1, x+1, b, c).ans);
		}
	}
    return 0;
}
