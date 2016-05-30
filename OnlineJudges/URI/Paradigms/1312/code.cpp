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

#define MAX 1100  
#define INF 1000000010

int n, m, x, y;

ll dp[MAX][MAX];
int mat[MAX][MAX];

ll solve(int i, int j) {

    if(i >= n || j >= n || i < 0 || j < 0) return 0;
    if(mat[i][j] == -INF) return 0;

    if(dp[i][j] != -INF) return dp[i][j];

    dp[i][j] = mat[i][j] + solve(i-1, j) + solve(i-1, j-1);
    return dp[i][j];
}

int main() {
 
    while(scanf("%d", &n) != EOF && n != 0) {

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mat[i][j] = -INF;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                scanf("%d", &mat[i][j]);
                dp[i][j] = -INF;
            }
        }


        ll ans = 0;
        for(int i = 0; i < n; i++) printf("%lld\n", solve(n-1, i));
 //       for(int i = 0; i < n; i++) solve(n-1, i);

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
                ans = max(ans, dp[i][j]);

        printf("%lld\n", ans);
    }

	return 0; 
}
