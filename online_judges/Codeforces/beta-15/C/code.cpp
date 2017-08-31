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

int n, m;
ll x, y;

int value(ll k) {
    if(k % 4 == 0) return 0;
    else if(k % 4 == 1) return k-1;
    else if(k % 4 == 2) return 1;
    else return k;
}

int main() {
 
    while(scanf("%d", &n) != EOF) {
        
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lld %lld", &x, &y);
            ans = ans ^ (value(x) ^ value(x+y));
        }
        printf("%colik\n", ans != 0 ? 't' : 'b');
    }

	return 0; 
}
