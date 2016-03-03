#include <bits/stdc++.h> 

#define MAX 103 
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

int n, m, x, y;
int freq[12];
string s;
ll memo[MAX][MAX/2][MAX/2][12];
ll C[MAX][MAX];

ll dp(int i, int even, int odd, int mod) {

    if(i > 9) return mod == 0;
    if(memo[i][even][odd][mod] != -1)
        return memo[i][even][odd][mod];
    
    ll result = 0;
    for(int j = 0; j <= freq[i]; j++){
        int k = freq[i] - j;
        if(j <= even && k <= odd) {
            ll mod2 = (((mod + i*j - k*i) % 11) + 11) % 11;
            ll aux = (C[even][j] * C[odd][k]) % MOD;
            result = (result + (aux*dp(i+1, even-j, odd-k, mod2))) % MOD; 
        }
    }
    return memo[i][even][odd][mod] = result;
}

void precalculate() {

    memset(C, 0, sizeof C);
    C[0][0] = 1;
    for(int i = 1; i < MAX; i++) {
        C[i][0] = 1; C[i][i] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
}

int main() {
    
    precalculate();


    while(cin >> s) {
        
        n = s.size();
        memset(freq, 0, sizeof freq);
        memset(memo, -1, sizeof memo);

        for(int i = 0; i < n; i++) freq[s[i] - '0']++;

        ll ans = 0LL;
        int mid1 = (n+1)/2;
        int mid2 = n/2;
        bool flag = n % 2 == 0;
        if(flag) mid2--; else mid1--;
        for(int i = 1; i <= 9; i++) {
            if(!freq[i]) continue;
            int mod = i;
            if(flag) mod = 11 - i;
            freq[i]--;
            memset(memo, -1, sizeof memo);
            ans = (ans + dp(0, mid1, mid2, mod)) % MOD;
            freq[i]++;
        }
        
        printf("%lld\n", ans);
    }

	return 0; 
}
