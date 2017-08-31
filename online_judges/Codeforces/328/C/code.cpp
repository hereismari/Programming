#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll unsigned long long
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int main() {
 

    ll n, x, y;
    cin >> n >> x >> y;

    if(x == y) { printf("1/1\n"); return 0; }
    ll m = y * (x /(__gcd(x,y)));
    ll ans = min(x,y) - 1;

    ll min_value = x-1 < y-1 ? x-1 : y-1;
    ans += (n/m)*(1 + min_value);
    if((n/m)*(m + min_value) >= n + 1) ans -= (n/m)*(m + min_value) - n -1;

    ll p = ans / __gcd(ans, n);
    ll q = n / __gcd(ans, n);
    
    cout << p << '/' << q << endl;

	return 0; 
}
