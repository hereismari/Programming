#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;


int edit_distance(string s1, string s2){

	int len1 = s1.size(), len2 = s2.size();

	int dp[len1 + 1][len2 + 1];
	dp[0][0] = 0;


	for(int i = 1; i <= len1; i++) dp[i][0] = i;
	for(int i = 1; i <= len2; i++) dp[0][i] = i;
	
	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			dp[i][j] = min(dp[i-1][j] + 1,min(dp[i][j-1] + 1, dp[i-1][j-1] + (s1[i-1] == s2[j-1]? 0: 1)));
		}
	}
	
	return dp[len1][len2];
}


int main() {
 
	string s1,s2;
	cin >> s1;
	cin >> s2;

	printf("%d",edit_distance(s1,s2));

	return 0; 
}
