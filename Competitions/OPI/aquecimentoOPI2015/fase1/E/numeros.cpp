#include <stdio.h>
#include <string.h>
#define MAX 400000000
using namespace std;

int dp[MAX];

int answer(int k){

	if(dp[k] != -1)
		return dp[k];
	if(k <= 1) return 0;
	if(k % 2)
		return dp[k] = (answer(k/2+1) + answer(k/2)) + 1;
	return dp[k] = (answer(k/2) + answer(k/2));
}

int main() {

	int n,t,k;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	dp[3] = 1;
	dp[2] = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d",&t,&k);
		answer(k);
		printf("%d %d\n",t,dp[k]);
	}

	return 0;
}
