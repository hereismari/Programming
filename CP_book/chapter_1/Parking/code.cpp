#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    while(n--) {
        
        int m;
        scanf("%d", &m);
        
        int a[m];
        for(int i = 0; i < m; i++) scanf("%d", &a[i]);

        sort(a, a + m);
        printf("%d\n", 2 * (a[m-1] - a[0]));
    }

    return 0;
}
