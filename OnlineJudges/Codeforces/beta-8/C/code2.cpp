#include <bits/stdc++.h> 

#define MAX (1 << 24) + 3
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
#define INF 1000000000
int n, a[300], b[300];
int dp[MAX][3], dist[300][300];

int distanceCalc(int x1, int x2, int y1, int y2) { 
    return pow(x1- x2, 2) + pow(y1 - y2, 2);
}

int solve(int mask) {
    
    if(mask >= (1 << n) - 1) return 0;
    if(dp[mask][0] != INF) return dp[mask][0];
    
    for(int j = 0; j < n; j++) {
        if((1 << j) & mask) continue;
        
        dp[mask][0] = dist[j][j] + solve(mask | (1 << j));
        dp[mask][1] = dp[mask][2] = j;
        for(int k = j+1; k < n; k++) {
            if((1 << k) & mask) continue;
            int result = solve(mask | (1 << j) | (1 << k)) + dist[j][k];
            if(result < dp[mask][0]) {
                dp[mask][2] = k;
                dp[mask][0] = result;
            }
        }
        break;
    }
    return dp[mask][0];
}

void printPath() {

    printf("0 ");
    int mask = 0;
    while(mask < (1 << n) - 1) {
        int aux = mask;
        printf("%d ", dp[mask][1] + 1);
        aux += (1 << dp[mask][1]);
        if(dp[mask][1] != dp[mask][2])
            printf("%d ", dp[mask][2] + 1), aux += (1 << dp[mask][2]);
        mask = aux;
        printf("0 ");
    }

}

int main() {
    int xIni, yIni;
    while(scanf("%d %d", &xIni, &yIni) != EOF) {
        
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
                dist[i][j] = dist[j][i] = distanceCalc(a[i],a[j],b[i],b[j]) + distanceCalc(a[i], xIni, b[i], yIni) +
                distanceCalc(a[j], xIni, b[j], yIni);           
        
        
        dp[0][0] = 0;
        for(int i = 0; i < (1 << n); i++) dp[i][0] = INF;
        
        solve(0);
        
        printf("%d\n", dp[0][0]);
        printPath();
    }

	return 0; 
}
