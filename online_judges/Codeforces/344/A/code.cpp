#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	
	int a[n], b[n], ans_a[n+1], ans_b[n+1];
	int ans = 0;

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	ans_a[0] = ans_b[0] = 0;
	for(int i = 1; i <= n; i++) {
		ans_a[i] = ans_a[i-1] | a[i-1];
		ans_b[i] = ans_b[i-1] | b[i-1];
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			ans = max(ans, ans_a[i] - ans_a[j-1] + ans_b[i] - ans_b[j-1]);

	printf("%d\n", ans);
	return 0;
}
