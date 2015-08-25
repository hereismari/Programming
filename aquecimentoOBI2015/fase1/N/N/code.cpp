#include <bits/stdc++.h>
#define ll long long 
#define MOD 2147483647
using namespace std;

ll expMatrix(ll n, ll exp) {
    if (exp == 0) return 1;
    if(exp == 1) return n;
    ll result = expMatrix(n, exp/2);
    result = (result * result) % MOD;
    if(exp & 1) result = n*result % MOD;
    return result;
}

int main() {

    ll n;
    cin >> n;
    cout << expMatrix(3,n) << '\n';
    return 0;
}
