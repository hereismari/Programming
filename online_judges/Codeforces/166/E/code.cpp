#include <stdio.h>
#define MOD 1000000007
#define MAX 10000001

#define ll long long int

using namespace std;
ll dp[MAX];

int main(){

	int n;
	scanf("%d",&n);
	
	dp[1] = 0;
	dp[2] = 3;	

	for(int i = 3 ; i <=n ; i++)
		dp[i] = (2LL * dp[i-1] + 3LL * dp[i-2]) % MOD;
	printf("%lld\n",dp[n]);
	return 0;
}
