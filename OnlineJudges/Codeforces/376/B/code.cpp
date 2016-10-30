#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n-1; i++) {
        if(a[i] % 2 == 0) continue;
        else if(a[i+1] > 0) { 
            a[i+1]--;
        }
        else { printf("NO\n"); return 0; }
    }

    if(a[n-1] % 2) { printf("NO\n"); return 0; }

    printf("YES\n");

    return 0;
}
