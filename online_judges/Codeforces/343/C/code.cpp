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

ll n, m, x, y;

int main() {
 
    while(scanf("%lld",&n) != EOF){
        
        set<ll> vol;
        scanf("%lld %lld", &x, &y);
    
        ll ans = x*x*y;
        vol.insert(x*x*y);    
        for(int i = 1; i < n; i++) {
            scanf("%lld %lld", &x, &y);
            ll vol_aux = x*x*y;
            set<ll>::iterator it = vol.lower_bound(vol_aux);
            ll base = 0LL;
            if(!vol.empty()) {--it; base = ((*it) < vol_aux) ? *(it): 0; vol.insert(base + vol_aux); }
            if(base + vol_aux > ans) ans = base + vol_aux;
            vol.insert(vol_aux);    
        }

        printf("%f\n", (double) ans*M_PI);
    }

	return 0; 
}
