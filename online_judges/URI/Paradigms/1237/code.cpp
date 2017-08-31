#include <bits/stdc++.h>
#define MAX 73

using namespace std;

int LCS(char s1[MAX], char s2[MAX]){
	
	int dp[MAX][MAX];
	memset(dp,0,sizeof dp);

	for(int i = 1; i <= strlen(s1); i++)
		for(int j = 1; j <= strlen(s2); j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}

	return dp[strlen(s1)][strlen(s2)];
}

int main() {

	char s1[MAX];
	char s2[MAX];
	
	while(scanf("\n%[^\n]s",s1) != EOF){
		scanf("\n%[^\n]s",s2);
		printf("%s\n%s\n",s1,s2);
		printf("%d\n",LCS(s1,s2));
	}

	return 0;
}
