#include <bits/stdc++.h> 

#define MAX 1000100 
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

int main() {
 
    while(scanf("%d %d", &n, &m) != EOF){

        ll ans = 1LL; 
        char c[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("\n%c", &c[i][j]);

        for(int j = 0; j < m; j++) {
            
            bool count[27]; 
            memset(count, false, sizeof count);
            ll aux = 0LL;
            for(int i = 0; i < n; i++) {
                count[c[i][j] - 'A'] = true;
            }
            for(int i = 0; i < 27; i++) aux += count[i];
            ans = (ans * aux) % MOD;
        }

        printf("%lld\n", ans);

    }

	return 0; 
}
