#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MOD 1000000007

#define MAX 1110

ll c, v;
ll dp[MAX];

ll solve(ll l) {

    if (l == 0) return 1;
    else if(dp[l] != -1) return dp[l];
    else {
        dp[l] = (solve(l-1) * v) % MOD;
        if(l != 1)
            dp[l] = (dp[l] + (((solve(l-2) * c) % MOD) * v) % MOD) % MOD;
    }
    return dp[l];
}

int main() {

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        printf("Case #%d: ", i+1);

        for(int j = 0; j < MAX; j++) dp[j] = -1;

        ll l;
        scanf("%lld %lld %lld", &c, &v, &l);

        printf("%lld\n", solve(l));
    }
    return 0;
}
