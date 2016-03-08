#include <bits/stdc++.h> 

#define MAX 101000 
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
 
    int t, k;
    scanf("%d %d", &t, &k);

    ll ans[MAX];

    for(int i = 0; i < MAX; i++)
        if(i >= k)
            ans[i] = (ans[i-1] + ans[i-k]) % MOD;
        else
            ans[i] = 1;

    for(int i = 1; i < MAX; i++) ans[i] = (ans[i] + ans[i-1]) % MOD;

    for(int i = 0; i < t; i++) {
        scanf("%d %d", &x, &y);
        printf("%lld\n", ((ans[y] + MOD) - ans[x-1]) % MOD);
    }

	return 0; 
}
