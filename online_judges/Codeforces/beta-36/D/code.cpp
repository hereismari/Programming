#include <stdio.h>
#define ll long long int
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t, k;
    scanf("%lld %lld", &t, &k);

    for(int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        if((n+m) % 2 || (n-k == 1 && m-k == 1)) printf("+\n");
        else printf("-\n");
    }

    return 0;
}
