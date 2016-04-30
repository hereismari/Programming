#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1300031

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX MOD

ll x, y, gcd;

void gcdExt(ll a, ll b) {
    if(b == 0) { x = 1; y = 0; gcd = a; return;}
    gcdExt(b, a % b);
    x = x - ( a / b)*y;
    swap(x, y);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
	ll a, b;
    	scanf("%lld %lld", &a, &b);
    	gcdExt(a/b, int(ceil(a/(1.0*b))));
	printf("%lld %lld\n", x * (a/gcd), y * (a/gcd));
    }
    
    return 0; 
}
