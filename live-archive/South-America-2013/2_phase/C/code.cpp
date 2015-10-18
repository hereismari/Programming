#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define range(i, n) for(int i=0; i<n; ++i)
typedef long long int ll;

ll count(ll x, ll bit) {
	ll span = 1LL<<(bit+1);
	return x/span * span/2 + max(x%span - span/2, 0LL);
}

ll solve(ll x) {
	ll bit;
	for(int i = 62; i >= 0; i--){
		if((1LL << i) & x) { bit = i; break; }
	}

	ll res = 0LL;
	range(j, bit+1) res = (res + count(x, j));
	return res;
}


int main() {
 
    ll n, m;
    while(scanf("%lld %lld",&n, &m) != EOF){	
	printf("%lld\n", solve(m+1) - solve(n));
    }

	return 0; 
}
