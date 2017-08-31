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
#define INF 1000000000


int main() {
 
    int n;
    double t;
    cin >> n >> t;

    double dp[n+3][n+3];
    int ans = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++) dp[i][j] = 0.0;

    dp[0][0] = t;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++) {
            if(dp[i][j] + 1e-10 >= 1) ans++;
            double left = max(dp[i][j] - 1, 0.0);
            dp[i+1][j] += left/2;
            dp[i+1][j+1] += left/2;
        }

    printf("%d\n", ans);
	return 0; 
}
