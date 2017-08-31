#include <bits/stdc++.h>

using namespace std;

#define MAX 100000 + 3
#define ll long long int

int main() {

    int n;
    int x;
    ll b[MAX], dp[MAX];

    scanf("%d", &n);

    memset(b, 0, sizeof b);
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        b[x]++;
    }

    dp[1] = b[1];
    for(int i = 2; i < MAX; i++) {
        dp[i] = max(b[i] * i + dp[i-2], dp[i-1]);
    }

    printf("%lld\n", dp[MAX-1]);

    return 0;
}
