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

#define MAX 2100  
#define INF 1000000000

ll cont[MAX];
int n, k, x, y;

void before(int a, int c) {

    if (c > k || a > n) return;

    cont[c] = (cont[c] + 1) % MOD;
    
    for(int i = a+a; i <= n; i += a) {
        before(i, c + 1);
    }
}

ll power(int a, int b) {
	
    ll x = 1, y = a;
     
    while(b > 0) {
        
        if(b % 2) {
            x = x * y;
            if(x > MOD) x %= MOD;
        }

        y = y * y;
        if(y > MOD) y %= MOD; 
        b /= 2;

    }
    
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
ll inverse(int n) {
    return power(n, MOD-2);
}
 
ll C(int a, int r) {
    ll f[a+1];
    f[0] = f[1] = 1;
    for (int i = 2; i <= a; i++) f[i] = (f[i-1]*i) % MOD;
    return (f[a] * ((inverse(f[r]) * inverse(f[a-r])) % MOD)) % MOD;
}
 
int main() {
 
    scanf("%d %d", &n, &k);

    memset(cont, 0, sizeof cont);
    
    for(int i = 1; i <= n; i++) before(i, 1);
	
	ll ans = 0LL;
	for(int i = 1; i <= k; i++) { 
        ans = (ans + C(k-1, i-1) * cont[i]) % MOD;
    }
	printf("%lld\n", ans);
	return 0; 
}
