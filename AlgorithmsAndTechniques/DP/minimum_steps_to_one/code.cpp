#include <string.h>
#include <stdio.h>
#define MAX 1001

using namespace std;

int n;
int m[MAX] = {};

int memoization(int n) {

 	int n2 = MAX,n3 = MAX,n1 = MAX;
	int res = MAX;
	
	if (n == 1)
		return 0;

	if (m[n-1] != -1)
		return m[n-1];
	n1 = 1 + memoization(n-1);
	
	if (n % 2 == 0)
		n2 = 1 + memoization(n/2);
	
	res = n1 < n2?n1:n2;

	if(n % 3 == 0)	
		n3 = 1 + memoization(n/3);

	res = res < n3?res:n3;
	
	m[n-1] = res;	
	return res;
}

int dp(int n){

	int dp[MAX];
	dp[1] = 0;
	for(int i = 2; i < n ; i++){
		dp[n] = 1 + dp[n-1];
		if(n % 2 == 0) dp[n] = dp[n] < (1 + dp[n/2])?dp[n]:(1+ dp[n/2]);
		if(n % 3 == 0) dp[n] = dp[n] < (1 + dp[n/3])?dp[n]:(1+ dp[n/3]);
	}
	
	return dp[n];
}

int main(){
	
	scanf("%d",&n);
	memset(m,-1,sizeof(m));
	printf("%d\n",memoization(n));
	return 0;
}
