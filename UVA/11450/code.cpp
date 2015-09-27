#include <bits/stdc++.h> 

#define MAX 25 
#define MAX2 225
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y, c;
int a[MAX][MAX];
int len[MAX];
ll memo[MAX][MAX2];

ll dp(int list, ll value) {
    
    if(value > m) return 0;
    if(list >= c) return value;
    if(memo[list][value] >= 0) return memo[list][value];

    ll ans = 0;
    for(int i = 0; i < len[list]; i++){
        ans = max(ans, dp(list + 1, value + a[list][i]));
    }

    return memo[list][value] = ans;
}

int main() {
 
    while(scanf("%d",&n) != EOF){

        while(n--) {
            
            memset(memo, -1, sizeof memo);

            scanf("%d %d", &m, &c);
            for(int i = 0; i < c; i++){
                scanf("%d", &len[i]);
                for(int j = 0; j < len[i]; j++) scanf("%d", &a[i][j]);
            }
        
            ll result = dp(0,0);
            if(result == 0) puts("no solution");
            else printf("%lld\n", dp(0, 0));

        }

    }

	return 0; 
}
