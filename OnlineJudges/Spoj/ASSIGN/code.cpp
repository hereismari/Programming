#include <bits/stdc++.h> 

#define MAX 22
#define MAX2 5000000
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

#define isBitOne(x, i) ((x >> i) & 1)

using namespace std; 

int n, m, x, y, t;
int mat[MAX][MAX];
ll dp[MAX2];

ll solve() {
    
    dp[0] = 1; // if set is empty we did it :)!

    for(int i = 1; i < (1 << n); i++) {

        int aux = 0;
        dp[i] = 0;

        for(int j = 0; j < n; j++) aux += isBitOne(i, j);
        for(int j = 0; j < n; j++) 
            if(mat[aux - 1][j] && isBitOne(i, j))
                dp[i] += dp[i & ~(1 << j)];
    }

    return dp[(1 << n) - 1];
}

int main() {

    scanf("%d", &t);
    while(t--) {
        
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        
        printf("%lld\n", solve());
    }

	return 0; 
}
