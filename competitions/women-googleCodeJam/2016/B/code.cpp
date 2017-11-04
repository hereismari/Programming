#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        printf("Case #%d: ", i+1);

        ll d, k, n;
        scanf("%lld %lld %lld", &d, &k, &n);

        n = n % d;

        ll c = (k + 1) > d ? 1 : k+1;
        ll inv = (k - 1) <= 0 ? d : k-1;

        if(k % 2 == 1) {
            c = (c + n*2) - d * ((c+n*2-1)/d);
            inv = (inv + n*2) - d * ((inv+n*2-1)/d);
        }
        else if(k % 2 == 0) {
            c = d * ((abs(c-n*2) + (c - n*2 <= 0? d:0))/d) + (c - n*2);
            inv = d * ((abs(inv-n*2) + (inv-n*2 <= 0? d: 0))/d) + (inv - n*2);
        }
        
        printf("%lld %lld\n", c, inv);
    }

    return 0;
}
