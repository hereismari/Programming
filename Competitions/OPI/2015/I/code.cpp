#include <bits/stdc++.h>
#define MAX 3000
#define INF 1 << 30;

using namespace std;

int n, m, a[MAX];
int dp[MAX][MAX];

int realValue(int i, int j) {
	int result = a[j];
	if (i) result -= a[i-1];
    result = (result + 5)/10;
    return result*10;
}

int DP(int index, int groups) {
    if(index >= n) return 0;
    if(groups == 0) return realValue(index, n-1); 
    if(dp[index][groups] >= 0) return dp[index][groups];
    
    int ans = INF;
	for(int j = index; j < n; j++) ans = min(ans, DP(j+1, groups-1) + realValue(index, j));
	return dp[index][groups] = ans;
}

int main() {

    while(scanf("%d %d",&n,&m) != EOF) {
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        for(int i = 1; i < n; i++) a[i] += a[i-1];
        memset(dp, -1, sizeof dp);
        printf("%d\n",DP(0,m));
    }
    return 0;
}
