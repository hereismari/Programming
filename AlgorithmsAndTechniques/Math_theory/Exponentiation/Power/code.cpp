#include <bits/stdc++.h>

#define ll long long int
#define MOD 1000000007
#define BASE 257

using namespace std;

ll power(ll num, ll pow) {
    if (pow < 1) return 1;
    ll result = power(num, pow/2);
    result = (result * result) % MOD;
    if (pow % 2)
        result = (result * num) % MOD;
	return result;
}

int main() {
    
    printf("Modular Inverse of BASE: %lld\n", power(BASE, MOD-2));
    return 0;
}
