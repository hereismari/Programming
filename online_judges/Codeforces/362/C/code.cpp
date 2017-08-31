#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define mp make_pair

int q;
ll x, y, v;
map<ll, ll> m;

void bfsUpd(ll a, ll b, ll value) {
    while(a != b) { 
        if(b > a) { m[b] += value; b /= 2; }
        else { m[a] += value; a /= 2; }
    }
}

ll bfs(ll a, ll b) {    
    ll res = 0LL;
    while(a != b) { 
        if(b > a ) { res += m[b]; b /= 2; }
        else { res += m[a]; a /= 2; }
    }
    return res;
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%d", &q);
        if(q == 1) {
            scanf("%lld %lld %lld", &x, &y, &v);
            bfsUpd(min(x, y), max(x, y), v);
        }
        else {
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", bfs(min(x, y), max(x, y))); 
        }
    }

    return 0;
}
