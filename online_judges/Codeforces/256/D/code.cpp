#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int n, m;

ll count(ll x) {
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) 
        ans += min((x-1)/i, m * (1LL));
    
    return ans;
}

ll binSearch(ll k) {
    
    ll b = 1LL, e = ((n*1LL)*m), mid, c;

    while(b <= e) {
        mid = b + (e-b)/2;
        c = count(mid); 
        if(c <= k) b = mid + 1;
        else if(c > k) e = mid - 1;
    }
    
    return e;
}

int main() {

    ll k;
    scanf("%d %d %lld", &n, &m, &k);
    printf("%lld\n", binSearch(k-1));
}
