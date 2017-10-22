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

#define MAX 100100  
#define INF 1000000000

int n, m, x, y, root;
int p, q, c, t;
ll v;
ll sqr[MAX], a[MAX], counter[MAX];

void makeSqrt() {
    memset(counter, 0, sizeof counter);
    memset(sqr, 0, sizeof sqr);
    memset(a, 0, sizeof a);
}

ll getQuery(int l, int r) { 
    ll res = 0;
    for(int i = l; i <= r;) {
        if(i % root == 0 && i + root - 1 <= r) {
            res += sqr[i/root] + counter[i/root] * root;
            i += root;
        }
        else {
            res += a[i] + counter[i/root];
            i++;
        }
    }

    return res;
}

void updateLazy(int l, int r, ll v) { 
    for(int i = l; i <= r;) {
        if(i % root == 0 && i + root - 1 <= r) {
            counter[i/root] += v;
            i += root;
        }
        else {
            sqr[i/root] += v;
            a[i] += v;
            i++;
        }
    }
}

int main() {
    
    root = (int) sqrt(MAX) + 1;

    scanf("%d", &t);
    while(t--) {

        scanf("%d %d", &n, &m);
        makeSqrt();

        for(int i = 0; i < m; i++) {
            scanf("%d", &c);
            if(c == 0) {
                scanf("%d %d %lld", &p, &q, &v);
                updateLazy(p, q, v);
            }
            else {
                scanf("%d %d", &p, &q);
                printf("%lld\n", getQuery(p, q));
            }
        }
    }

    return 0; 
}
