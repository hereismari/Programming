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

int main() {
 
    scanf("%d %d", &n, &k);

    ll dp[k+1][n+1];
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for(int i = 1; i <= n; i++) dp[1][i] = 1;
    
    for(int i = 2; i <= k; i++)
        for(int j = 1; j <= n; j++)
            for(int l = j; l <= n; l += j)
                dp[i][j] = (dp[i][j] + dp[i-1][l]) % MOD;

	ll ans = 0LL;
	for(int i = 1; i <= n; i++) { 
        ans = (ans + dp[k][i]) % MOD;
    }

	printf("%lld\n", ans);
	return 0; 
}
