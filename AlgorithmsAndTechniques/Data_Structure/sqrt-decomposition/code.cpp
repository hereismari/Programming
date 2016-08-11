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
ll sqr[MAX], a[MAX], counter[MAX];

void makeSqrt() {

    memset(counter, 0, sizeof counter);
    memset(sqr, 0, sizeof sqr);
    
    for(int i = 0; i < n; i++) sqr[i/root] += a[i];
}

ll getQuery(int l, int r) { 

    ll res = 0;
    for(int i = l; i <= r;) {
        if(i % root == 0 && i + root - 1 <= r) {
            res += sqr[i/root];
            i += root;
        }
        else {
            res += a[i];
            i++;
        }
    }

    return res;
}

void updateLazy(int l, int r) { 
    for(int i = l; i <= r;) {
        if(i % root == 0 && i + root - 1 <= r) {
            counter[i/root]++;
            i += root;
        }
        else {
            a[i] = max(0LL, a[i]-1);
            sqr[i/root] = max(0LL, sqr[i/root]-1);
            i++;
        }
    }
}

void updateQuery(int i) {
    
    ll c = max(a[i] - counter[i/root], 0LL);
    
    ll l = max(i - c, 0LL);
    ll r = min(i + c, (n-1)*1LL);

    updateLazy(l, r);
}

int main() {
 
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    
    root = (int) sqrt(n) + 1;
    makeSqrt();

    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        updateQuery(x-1);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(0LL, a[i] - counter[i/root]);
    }

    printf("%lld\n", ans);

    return 0; 
}
