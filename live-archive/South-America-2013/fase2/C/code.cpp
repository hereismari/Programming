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

ll n, m;
ll count(ll x, ll bit) {
        ll span = 1LL << (bit+1);
        return x/span * span/2 + max(x%span - span/2, 0LL);
}
int main() {
 
    while(scanf("%lld %lld",&n, &m) != EOF){
        printf("%lld\n", count(m+1,16));
        printf("%lld\n", count(m+1,16) - count(n, 16));
    }

	return 0; 
}
