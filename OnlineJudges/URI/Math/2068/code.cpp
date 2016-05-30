#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll t1, t2, n;

int main() {

    scanf("%lld %lld %lld", &t1, &t2, &n);

    ll interval = (t2-t1)*60;
    ll a, b;

    // area de toda a regiao
    b = interval*interval;
    
    // area dos encontros validos
    a = interval*interval - (interval-n)*(interval-n);

    ll mdc = __gcd(b, a);
    printf("%lld/%lld\n", a/mdc, b/mdc);
}
