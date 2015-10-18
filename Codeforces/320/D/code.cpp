#include <bits/stdc++.h> 

#define MAX 1000100 
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

int n, m, x, y, k;

int main() {
 

    scanf("%d %d %d", &n, &m, &k);
    ll a[n+1], l[n+1], r[n+2];
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    
    ll multi = 1;
    while(m--) multi *= k;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    for(int i = 1; i <= n; i++) {l[i] = a[i]; l[i] |= l[i-1];}
    for(int i = n; i >= 1; i--) {r[i] = a[i]; r[i] |= r[i+1];}

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, l[i-1] | a[i] * multi | r[i+1]);
    }
    printf("%lld\n", ans);
	return 0; 
}
