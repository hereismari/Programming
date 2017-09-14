#include <bits/stdc++.h>


long long int MOD = 1000000000 + 7;

using namespace std;

int main() {

	int t, n, m;
	// 3,  2,  5
	
	// 2 3 2
	// 2 3 4
	
	// 3 2 3
	// 3 4 3
	// 3 4 5
	
	// 4 3 2
	// 4 3 4
	// 4 5 4
	
	// 5 4 5
	// 5 4 3
	
	// dp[t][i] = dp[t-1][i-1] + dp[t-1][i+1];
	// dp[1][i] = 1;
	
	// dp[2][2] = 1, dp[2][3] = 2, dp[2][4] = 2, dp[2][5] = 1
	
	// dp[3][2] = 2, dp[2][3] = 3, dp[2][4] = 3, dp[2][5] = 2
	
	scanf("%d %d %d", &t, &n, &m);
	
	long long int dp[t][m+n+1];
	
	for(int i = 0; i < t; i++)
		for(int j = n; j <= m; j++) {
			if(i == 0) dp[i][j] = 1;
			else dp[i][j] = 0;
		}

	for(int i = 1; i < t; i++) {
		for(int j = n; j <= m; j++)
		if(j > n && j < m) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
		else if(j == n) dp[i][j] = dp[i-1][j+1];
		else dp[i][j] = dp[i-1][j-1];
	}
	
	long long int ans = 0;
	for(int i = n; i <= m; i++) ans = (ans + dp[t-1][i]) % MOD;
	
	printf("%lld\n", ans);
	
	return 0;
}
