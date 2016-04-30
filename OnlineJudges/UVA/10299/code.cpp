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

ll  phi(ll  n) {
	ll res = n;
	for (ll i = 2 ; i * i <= n ; ++ i )
		if(n % i == 0) {
			while(n % i == 0 )
				n /= i ;
			res -= res / i ;
		}
	if (n > 1) res -= res / n ;
	return res ;
}

int main(){
    ll n ;
    while(scanf("%lld",&n) && n){
        if(n == 1) puts("0");
        else printf("%lld\n",phi(n));
    }
}
