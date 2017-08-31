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

void solve() {

    dp[0][0] = 0;
    for(int i = 1; i < (1 << n); i++) dp[i][0] = INF;
    for(int i = 0; i < (1 << n); i++) {
        
        if(dp[i][0] == INF) continue;
            for(int j = 0; j < n; j++) {
                if((1 << j) & i) continue;

                for(int k = j; k < n; k++) {
                    if((1 << k) & i) continue;
                    int status = i | (1 << j) | (1 << k);
                    if(dp[status][0] > dp[i][0] + dist[j][k]) {
                        dp[status][0] = dp[i][0] + dist[j][k];
                        dp[status][1] = j;
                        dp[status][2] = k;
                    }
                }
                break;
            }
    }
}

void printPath() {

    printf("0 ");
    int mask = (1 << n) - 1;
    while(mask) {
        int aux = mask;
        printf("%d ", dp[mask][2] + 1);
        aux -= (1 << dp[mask][2]);
        if(dp[mask][1] != dp[mask][2])
            printf("%d ", dp[mask][1] + 1), aux -= (1 << dp[mask][1]);
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
                distanceCalc(a[j], xIni,
                b[j], yIni);           
        
        solve();
        printf("%d\n", dp[(1 << n) - 1][0]);
        printPath();
    }

	return 0; 
}
