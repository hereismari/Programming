#include <bits/stdc++.h> 

#define MAX 110 
#define ll long long int
 
using namespace std; 

int n, m, x, y;
ll dp[MAX][MAX], a[MAX];

ll solve(int index, int size) {

    if(size == 1) return dp[index][size] = 1LL;
    if(dp[index][size] != -1) return dp[index][size];

    dp[index][size] = 0;
    for(int i = index - 1; i >= 0; i--)
        if(a[index] > a[i])
            dp[index][size] += solve(i, size -1);

    return dp[index][size];
}

int main() {
 
    while(scanf("%d %d",&n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        memset(dp, -1, sizeof dp);    
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        ll ans = 0;
        for(int i = m-1; i < n; i++) ans += solve(i, m);
        printf("%lld\n", ans);   
    
    }

	return 0; 
}
