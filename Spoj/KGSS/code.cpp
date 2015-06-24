#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#define MAXN 100100
#define INF 1000001000

int n, a[MAXN];
int b, c, d , i, m, x;
char op;

struct data {
	int greater, greater2, ans;
};

data t[2000000];

data combine (data l, data r) {
	data res;
	
	res.greater = max(l.greater,r.greater);
	res.greater2 = max(max(l.greater2,r.greater2),min(l.greater,r.greater));
	res.ans = max(max(l.ans,r.ans), res.greater + res.greater2);
//	printf("%d %d\n",res.greater,res.greater2);
//	printf("%d\n",res.ans);
	return res;
}

data make_data (int val) {
	data res;
	res.ans = val;
	res.greater = max(-1000000, val);
	res.greater2 = 0;
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
    scanf("%d", &x);
    for(int i = 0 ; i < x ; i++) {
        scanf("%d", &a[i+1]);
    }
    build(a, 1, 1, x+1);
    scanf("%d",&m);
	for(int i = 0; i <  m; i++) {
        scanf("\n%c %d %d", &op, &b, &c);
        if (op == 'U') update(1,1,x+1,b,c);
		else printf("%d\n", query(1, 1, x+1, b, c).ans);
    }
    return 0;
}
