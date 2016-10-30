#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {


    ll a[3];
    scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);

    sort(a, a + 3);
    ll v1 = max(a[2] - 1 - a[0], 0LL);
    ll v2 = max(a[2] - 1 - a[1], 0LL);
    
    printf("%lld\n", v1 + v2);
    return 0;
}
