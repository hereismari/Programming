#include <bits/stdc++.h>
#define MAX 2000

using namespace std;

bool dp[MAX][MAX];
int a[MAX];
int n, m;

void solve() {
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < m; j++){
			if(dp[i-1][j]){
				dp[i][j] = true;
				dp[i][(j + a[i]) % m] = true;
			}
		}
}

int main() {

	scanf("%d %d", &n, &m);	
	for(int i = 1; i <=n; i++) scanf("%d", &a[i]);

	if(n > m) { printf("YES\n"); return 0;}
	for(int i = 1; i <= n; i++) dp[i][a[i] % m] = true;
	solve();
	printf("%s\n", dp[n][0] ? "YES" : "NO");

	return 0;
}
