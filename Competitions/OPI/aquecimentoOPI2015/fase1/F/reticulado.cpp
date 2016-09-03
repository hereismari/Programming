#include <stdio.h>
#include <string.h>
#define ll long long int

using namespace std;

ll dp[1001];

ll gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll answer(int x) {
	if(dp[x] > 0) return dp[x];
	int count = 0;
	dp[x] = (answer(x-1) + 2);
	for(int i = 2; i <= x; i++){
		if(gcd(i,x) == 1)
			dp[x] += 2;
	}
	return dp[x];
}

int main() {

	memset(dp,0,sizeof dp);
	dp[1] = 3;
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d",&x);
		printf("%d %d %lld\n",i,x,answer(x));
	
	}
	return 0;
}
