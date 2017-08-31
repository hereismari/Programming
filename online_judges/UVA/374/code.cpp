#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll m; 

ll power(ll num, ll pow) {
    if (pow == 0) return 1;
    ll result = power(num, pow/2) % m;
    result = (result * result) % m;
    if (pow % 2 != 0) result = (result * num) % m;
    return result;
}

int main() {

    ll b, p;
    while(scanf("%lld %lld %lld", &b, &p, &m) != EOF) {
        printf("%lld\n", power(b, p));
    }

	return 0;
}
