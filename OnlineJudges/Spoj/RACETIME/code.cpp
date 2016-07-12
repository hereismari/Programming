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

#define MAX 100010  
#define INF 1000000000

int n, m, y, root;
int p, q;
char c;

struct node {
    
    int id;
    ll v;
    
    node(int id = 0, ll v = 0) {
        this->id = id;
        this->v = v;
    }

    bool operator < (const node &o) const {
        return v < o.v;    
    }

};

ll x;
node a[MAX], b[MAX];

void makeSqrt() {
    for(int i = 0; i < n; i+= root)
        sort(b + i, b + min(i + root, n));
}

int binSearch(int l, int r, ll v) {
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(b[mid].v < v) l = mid + 1;
        else if(b[mid].v > v) r = mid - 1;
        else if(l != r) l = mid;
        else return mid;
    }

    return l;
}

ll getQuery(int l, int r, ll v) { 

    ll res = 0;
    for(int i = l; i <= r;) {
        if(i % root == 0 && i + root - 1 <= r) {
            res += binSearch(i, i + root -1, v);
            i += root;
        }
        else {
            res += a[i].v <= v;
            i++;
        }
    }

    return res;
}

void update(int i, ll v) {

    for(int j = i/root;; j++)
        if(a[j].id == i) {
            a[j].v = v;
            b[j].v = v;
            sort(b + i/root * root, b + min(i/root * root + root, n));
            break;
        }
}

int main() {
    
    scanf("%d %d", &n, &m);
    root = (int) sqrt(n) + 1;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        a[i] = node(i, x);
        b[i] = a[i];
    }

    for(int i = 0; i < m; i++) {
        scanf("\n%c", &c);
        if(c == 'C') {
            scanf("%d %d %lld", &p, &q, &x);
            printf("%lld\n", getQuery(p-1, q-1, x));
        }
        else {
            scanf("%d %lld", &p, &x);
            update(p-1, x);
        }
    }

    return 0; 
}
