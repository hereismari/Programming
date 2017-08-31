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

ll n;

bool verify(ll x) { for(ll i = 2; i * i <= x; i++) if( x  % (i*i) == 0) return true; return false; }
int main() {
 
    while(scanf("%lld",&n) != EOF){
        
        ll ans = 0LL;
        for(ll i = 1; i * i <= n; i++) 
            if(n % i == 0) {
                if(!verify(i)) ans = max(ans, i);
                if(!verify(n/i)) ans = max(ans, n/i);       
            }
       
        printf("%lld\n", ans);
    }

	return 0; 
}
