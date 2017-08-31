#include <bits/stdc++.h> 

#define MAX 1001
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
 
using namespace std; 

int n, k, d;
ll dp[MAX][MAX];

int main() {
    
    cin >> n >> k >> d;

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i - j < 0) break;
            if(j < d) {
                dp[i][0] = (dp[i-j][0] + dp[i][0])  % MOD;
                dp[i][1] = (dp[i-j][1] + dp[i][1])  % MOD;
            }
            else {
                dp[i][1] = (dp[i-j][0] + dp[i][1]) % MOD;
                dp[i][1] = (dp[i-j][1] + dp[i][1]) % MOD;
            }
        }
    }

    cout << dp[n][1] << endl;
    return 0;
}
