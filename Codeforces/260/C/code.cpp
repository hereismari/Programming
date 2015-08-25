#include <bits/stdc++.h>
#define MAX 100015
#define ll long long int

using namespace std;

ll a[MAX], freq[MAX], dp[MAX];

int main() {

	int n;
	scanf("%d",&n);

	memset(freq, 0, sizeof freq);
	for(int i = 0; i < n; i++){
		scanf("%lld",&a[i]); freq[a[i]]++;
	}

	dp[0] = 0;
	dp[1] = freq[1];

	for(int i = 2; i < MAX; i++){
		dp[i] = max(dp[i-1], dp[i-2] + freq[i]*i);
	}

	printf("%lld\n", dp[MAX-1]);
	return 0;
}
