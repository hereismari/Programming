#include <bits/stdc++.h> 

using namespace std; 

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

#define INF 1000000000

#define Q_MAX 300000
#define N 30100
#define MAX_VALUE 2000000

int root;

struct query {
    
    int l, r, id;
    query(int l = 0, int r = 0, int id = -1) {
        this->l = l;
        this->r = r;
        this->id = id;
    }

    bool operator < (const query &o) const {
        if(o.l/root != l/root) return l/root < o.l/root;
        else return r < o.r;
    }
};

int n, m, x, y, res;
int a[N], cont[MAX_VALUE + 1];
query q[Q_MAX + 1];

void add(int pos) { 
    int e = a[pos];
    cont[e]++;
    if(cont[e] == 1) res++;
}

void rmv(int pos) { 
    int e = a[pos];
    cont[e]--;
    if(!cont[e]) res--;
}

int main() {
 
    root = (int) sqrt(N) + 1;

    while(scanf("%d", &n) != EOF) {

        res = 0;
        memset(cont, 0, sizeof cont);

        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            q[i] = query(x-1, y-1, i);
        }

        sort(q, q + m);
        
        int ans[m];
        int l = 0, r = 0;
        for(int i = 0; i < m; i++) {
            while(l < q[i].l) rmv(l++);
            while(l > q[i].l) add(--l);
            while(r <= q[i].r) add(r++);
            while(r > q[i].r + 1) rmv(--r);

            ans[q[i].id] = res;
        }

        for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
    }

	return 0; 
}
