#include <bits/stdc++.h>
#define MAX 102

using namespace std;

int k, n;
int x,y;

int v[MAX];
int w[MAX];
int dp[MAX][MAX];

int knap(int cap) {


	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= cap; j++){
			if(i == 0 || j == 0) dp[i][j] = 1;
			else if(w[i] <= j)
				dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	} 

	return dp[k][cap];
}

int knapR(int index, int cap){

	if(dp[index][cap] >= 0) return dp[index][cap];
	
	if(index == 1){
		if(w[index] <= cap)
			return dp[index][cap] = v[index];
		else
			return dp[index][cap] = 0;
	}

	int dont_put = knapR(index-1,cap);
	int answer = dont_put;
	if(w[index] <= cap)
		answer = max(answer,knapR(index-1,cap - w[index]) + v[index]);
	return dp[index][cap] = answer;
}

int main() {

	while(true){
		scanf("%d",&k); if(k == 0) break;
		scanf("%d",&n);
		for(int i = 1; i <= k; i++){
			scanf("%d %d",&v[i],&w[i]);
		}
		
		memset(dp,-1,sizeof dp);
		printf("%d min.\n",knapR(k,n));
	}
	return 0;
}
