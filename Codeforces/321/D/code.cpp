#include <bits/stdc++.h> 

#define MAX 19
#define MAX2 624288
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y, k;
ll value[MAX][MAX], s[MAX], inc, state[MAX2][MAX];

ll dp(int bitmask, int prev) {
    
    if(__builtin_popcount(bitmask) == m) return 0;
    if(prev >= 0 && state[bitmask][prev] >= 0) return state[bitmask][prev];

    ll ans = 0;
    for(int i = 0; i < n; i++)
        if(!(bitmask & (1 << i)))
            ans = max(ans, (prev != -1 ? value[prev][i] : 0) + s[i] + dp(bitmask | (1 << i), i));
           
    return state[bitmask][prev] = ans;
}

int main() {
 
    scanf("%d %d %d", &n, &m, &k);
    memset(value, 0 , sizeof value);
    memset(state, -1 , sizeof state);
    
    for(int i = 0; i < n; i++) scanf("%lld", &s[i]);
    for(int i = 0; i < k; i++){
        scanf("%d %d %lld", &x, &y, &inc);
        value[x-1][y-1] = inc;
    }

    printf("%lld\n", dp(0, -1));
	return 0; 
}
