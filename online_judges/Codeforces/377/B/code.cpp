#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] + a[i-1] < m) {
            ans += m - (a[i] + a[i-1]);
            a[i] += m - (a[i] + a[i-1]);
        }
    }

    printf("%d\n", ans);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
