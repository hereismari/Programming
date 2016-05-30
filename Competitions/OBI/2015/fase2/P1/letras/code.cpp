#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 1000100  

int n, m, x, y;

int main() {
 
    string s;
    cin >> s;
    
    int dp[30];
    for(int i = 0; i < 26; i++) dp[i] = 0;

    int ans = 1;
    for(int i = 0; i < s.size(); i++) {
        int aux = 0;
        for(int j = 0; j <= s[i]-'A'; j++)
            aux = max(aux, dp[j] + 1);
        dp[s[i]-'A'] = max(dp[s[i]-'A'], aux);
        ans = max(ans, dp[s[i]-'A']);
    }

    printf("%d\n", ans);
	return 0; 
}
