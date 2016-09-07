#include <bits/stdc++.h>

using namespace std;

#define ll long long int 
#define MOD 1000000007
#define MAX 100004

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    ll dp[MAX];
    memset(dp, 0, sizeof dp);
    
    for(int i = 0; i < MAX; i++) {
        if(i < k) dp[i] = 1;
        else {
            dp[i] = (dp[i-1] + dp[i-k]) % MOD;
        }
    }

    for(int i = 1; i < MAX; i++) dp[i] = (dp[i] + dp[i-1]) % MOD;

    while(n--) {
        
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", (dp[b] + MOD - dp[a-1]) % MOD);

    }

    return 0;
}
