#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, a[3];
	scanf("%d %d %d %d\n", &n, &a[0], &a[1], &a[2]);
	
	int dp[n+3];
	for(int i = 0; i <= n; i++) dp[i] = -4040;
	
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			if(a[j] <= i)
				dp[i] = max(dp[i], dp[i - a[j]] + 1);
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
