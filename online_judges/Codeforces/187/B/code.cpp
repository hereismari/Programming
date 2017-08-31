#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {

    int n, m;
    int op, id;
    ll x;

    scanf("%d %d", &n, &m);

    ll a[n], inc[n], sum;

    sum = 0LL;
    for(int i = 0; i < n; i++) {
        inc[i] = 0LL;
    }

    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    
    for(int i = 1; i <= m; i++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d %lld", &id, &x);
            a[id-1] = x;
            inc[id-1] = sum;
        }
        else if(op == 2) {
            scanf("%lld", &x);
            sum += x;
        }
        else {
            scanf("%d", &id);
            printf("%lld\n", a[id-1] + sum - inc[id-1]);
        }
    }

    return 0;
}
