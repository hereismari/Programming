#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

ll TEN_18 = 10000000000000000;
ll n, a, b;
ll l[MAX];
vector<ll> test;

void fillTest(ll x) {
    if(x % 2 == 0) test.pb(2);
    while(x % 2 == 0) x = x/2;

    for(ll i = 3; i <= sqrt(x); i = i + 2) {
        if(x % i == 0) test.pb(i);
        while(x % i == 0) x /= i;
    }

    if(x > 2) test.pb(x);
}

ll solve(ll p) {

    ll s1[n+1], s2[n+1], dp[n+1], c[n+1];
    for(int i = 0; i < n+1; i++) {
        s1[i] = dp[i] = 0;
        c[i] = TEN_18;
    }
    for(int i = 0; i < n; i++) {
        if(l[i] % p == 0) c[i] = 0;
        else if((l[i] + 1) % p == 0 || (l[i] - 1) % p == 0) c[i] = b;
        //printf("l[%d] = %lld, c[%d] = %lld\n", i, l[i], i, c[i]);
    }

    s2[n] = 0LL;
    for(int i = n-1; i >= 0; i--) {
        s2[i] = min(c[i] + s2[i+1], TEN_18);
        dp[i] = min(dp[i+1] + a, s2[i]); 
        //printf("dp[%d] = %lld\n", i, dp[i]);
   }
    
    ll result = dp[0];
    s1[0] = 0LL;
    for(int i = 1; i < n; i++) { 
        s1[i] = min(s1[i-1] + c[i-1], TEN_18);
        result = min(s1[i] + dp[i], result);
        //printf("%d, %lld\n", i, result);
    }

    return result;
}

int main() {
 
    while(scanf("%lld %lld %lld", &n, &a, &b) != EOF){

        test.clear();
        for(int i = 0; i < n; i++) scanf("%lld", &l[i]);
        
        fillTest(l[0]); fillTest(l[0] + 1); fillTest(l[0]-1);
        fillTest(l[n-1]); fillTest(l[n-1] + 1); fillTest(l[n-1]-1);

        ll ans = TEN_18;
        for(int i = 0; i < test.size(); i++) {
            //printf("%lld\n", test[i]);
            ans = min(ans, solve(test[i]));
        }
        printf("%lld\n", ans);
    }

	return 0; 
}
