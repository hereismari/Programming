#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {

    int t;
    scanf("%d", &t);

    int c = 1;
    while(c <= t) {
        int n;
        scanf("%d", &n);

        ll a[n*2];
        for(int i = 0; i < n*2; i++) scanf("%lld", &a[i]);
        
        printf("Case #%d:", c++);
        
        int size = 0;
        for(int i = 0; i < 2*n && size != n; i++) {
            if(a[i] == -1) continue;
            for(int j = i+1; j < n*2; j++) {
                if(a[j] - a[i] == a[j] * 0.25) {
                    printf(" %lld", a[i]);
                    a[i] = a[j] = -1;
                    size++;
                    break;
                }
            }
        }

        printf("\n");
    }

    return 0;
}
