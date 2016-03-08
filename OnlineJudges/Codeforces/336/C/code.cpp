#include <bits/stdc++.h> 

#define MAX 100010 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
#define MAX_VALUE 1000000 + 2

using namespace std; 

int n, m, x, y;
int p[MAX_VALUE],  dp[MAX_VALUE];

int main() {
 
    while(scanf("%d",&n) != EOF) {
        
        for(int i = 0; i < MAX_VALUE; i++) dp[i] = p[i] = 0;
        
        for(int i = 0; i < n; i++) { 
            scanf("%d %d", &x, &y);
            p[x] = y;
        }

        int ans = 0;
        dp[0] = (p[0] != 0);

        for(int i = 1; i <= MAX_VALUE-2; i++) {
            if(p[i] == 0) dp[i] = dp[i-1];
            else {
                if(p[i] >= i) dp[i] = 1;
                else dp[i] = dp[i - p[i] - 1] + 1; 
            }
            if(dp[i] > ans) ans = dp[i];
        }
    
        printf("%d\n", n - ans);
    }

	return 0; 
}
