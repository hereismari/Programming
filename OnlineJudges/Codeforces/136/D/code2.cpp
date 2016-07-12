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

#define N 100001
#define MAX 300100
#define INF 1000000000

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
int a[MAX];

int cont[MAX], id[MAX];
query q[MAX];

void add(int pos) { 
    
    if(a[pos] >= N) return;
    
    int e = a[pos];
    cont[e]++;
    if(cont[e] == e) res++;
    else if (cont[e] == e + 1) res--;
}

void rmv(int pos) { 
    
    if(a[pos] >= N) return;

    int e = a[pos];
    cont[e]--;
    if(cont[e] == e-1) res--;
    if(cont[e] == e) res++;
}

int main() {
 
    root = (int) sqrt(N) + 1;

    while(scanf("%d %d", &n, &m) != EOF) {

        res = 0;

        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
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
            while(r > q[i].r+1) rmv(--r);

            ans[q[i].id] = res;
        }

        for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
    }

	return 0; 
}
