#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 && a[i] != 0) ans++;
        else {
            
            if(a[i] == 1 && (a[i-1] != 1)) ans++;
            else if(a[i] == 1 && a[i-1] == 1) a[i] = 0;

            else if(a[i] == 2 && (a[i-1] != 2)) ans++;
            else if(a[i] == 2 && a[i-1] == 2) a[i] = 0;
            
            else if(a[i] == 3 && a[i-1] == 2) {
                ans++;
                a[i] = 1;
            }
            else if(a[i] == 3 && a[i-1] == 1) {
                ans++;
                a[i] = 2;
            }
            else if(a[i] == 3) ans++;
        }
    }

    printf("%d\n", n - ans);
    return 0;
}
