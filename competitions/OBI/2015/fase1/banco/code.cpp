#include <bits/stdc++.h>
#define MAX 5020
#define ll long long int
using namespace std;

int n;
int v[] = {2,5,10,20,50,100};
int q[6];
ll dp[MAX];

ll answer() {

	memset(dp,0, sizeof dp);
	dp[0] = 1;
	for(int i = 5; i >= 0; i--)
		for(int j = n; j >= 0; j--)
			for(int k = 1; k <= q[i] && v[i]*k <= j; k++){
				dp[j] += dp[j - k * v[i]];
			}

	return dp[n];
}

int main() {
	
	scanf("%d",&n);
	for(int i = 0; i < 6; i++) scanf("%d",&q[i]);
	printf("%lld\n",answer());
	return 0;
}
