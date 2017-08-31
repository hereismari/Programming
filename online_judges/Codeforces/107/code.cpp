#include <bits/stdc++.h> 

using namespace std; 

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

#define MAX 1000100  

ll n, m, x, y;

int main() {
 
    while(scanf("%lld", &n) != EOF) {
        
        vector<ll> div;
        for(ll i = 2; i*i <= n; i++) {
            while(n % i == 0) {
                n /= i;
                div.pb(i);
            }
        }

        if(n != 1) div.pb(n);
        
        if(div.size() <= 1) printf("1\n0\n");
        else if (div.size() == 2) printf("2\n");
        else printf("1\n%lld\n", div[0] * div[1]);
    }

	return 0; 
}
