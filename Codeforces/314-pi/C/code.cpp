#include <bits/stdc++.h>
#define MAX 300000
#define ll long long

using namespace std;

int main() {

    ll a[MAX];
    ll n, k;
    scanf ("%lld %lld", &n, &k);
    map <ll, ll> left, right;

    for(int i = 0; i < n; i++){
        scanf ("%lld", &a[i]);
        right[a[i]]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x = a[i];
        right[x]--;
        if (x % k == 0)
            ans += (left[x / k] * right[x * k]);
        left[x]++;
    }

    printf ("%lld\n", ans);
    return 0;
}

